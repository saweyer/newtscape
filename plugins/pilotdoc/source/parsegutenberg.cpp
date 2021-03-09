#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <afx.h>

#define BUF_LEN 132
#define MIN_SECTION_LEN 1024
#define NL "\r"
#define DEVNULL_FILE "md8tmp.tmp"

typedef int boolean;

// The minimum line length before the program decides that
//  an intra paragraph line break is intentional.  GP defines
//  the minimum line as 51, but in practice is is sometimes
//  found shorter for no apparent reason.
#define GP_MIN_LINE 45


CString AppendNumber (const char *s, int n)
{
	CString	cstr(s);
	char	buffer[8];

	if (n < 10) cstr += "0";
	cstr = cstr + _ltoa(n, buffer, 10);

	return cstr;
}


CString SanitizeLine (const char *s)
{
	CString	cstr(s);

	// remove pesky trailing CRs (and blanks)
	cstr.TrimRight();

	// strip leading blanks
	cstr.TrimLeft();

	return cstr;
}


void CreatePDB (const CString &dest, const CString &story, int para_num)
{
	CString				text_file_name;
	CString				pdb_file_name;
	CString				story_name;
	CString				cmdLine;
	STARTUPINFO			startinfo;
	PROCESS_INFORMATION	pinfo;
	unsigned long		lpExitCode;
	boolean				done;

	text_file_name = AppendNumber(dest, para_num) + ".txt";
	pdb_file_name = AppendNumber(dest, para_num) + ".pdb";
	story_name = AppendNumber(story+"-", para_num);

	startinfo.cb = sizeof(STARTUPINFO);
	startinfo.lpReserved = NULL;
	startinfo.lpDesktop = NULL;
	startinfo.lpTitle = NULL;
	startinfo.dwFlags = STARTF_USESHOWWINDOW;
	startinfo.cbReserved2 = 0;
	startinfo.lpReserved2 = NULL;
	startinfo.wShowWindow = SW_SHOW;

	cmdLine = "makedoc8 ";
	cmdLine += text_file_name + " ";
	cmdLine += pdb_file_name + " ";
	cmdLine += story_name + " >" + DEVNULL_FILE;
	CreateProcess(NULL, (char *)(const char *)cmdLine, NULL, NULL, 0, 0,
					NULL, NULL, &startinfo, &pinfo);

	done = false;
	while (!done) {
		GetExitCodeProcess(pinfo.hProcess, &lpExitCode);
		//cout << "exit code=" << lpExitCode << endl;
		if (lpExitCode != STILL_ACTIVE) {
			//cout << "exit code=" << lpExitCode << endl;
			done = TRUE;
		} else {
			Sleep(200);
		}
	}

	// delete the temporary text files
	remove(text_file_name);
	remove(DEVNULL_FILE);
}


boolean ParseParagraph (ifstream &ssource, const CString &dest, int para_num)
{
	char		buffer[BUF_LEN];
	CString		section;
	CString		paragraph;
	CString		line;
	CString		file_name;
	int			prev_line_len;
	boolean		end_paragraph;
	boolean		end_section;
	int			cr_count;
	ofstream	outfile;

	file_name = AppendNumber(dest, para_num) + ".txt";
	
	cout << "Generating:  " << AppendNumber(dest, para_num) << ".pdb" << endl;


	// eat any leading space (probably shouldn't be any)
	while (paragraph.IsEmpty() && !ssource.eof()) {
		ssource.getline(buffer, BUF_LEN);
		line = SanitizeLine(buffer);
		paragraph += line;
		prev_line_len = strlen(buffer);	// get len before sanitize!
	}

	// suck up the entire section...
	end_section = false;
	cr_count = 0;
	while (!end_section && !ssource.eof()) {
		end_paragraph = false;
		while (!end_paragraph && !ssource.eof()) {
			ssource.getline(buffer, BUF_LEN);
			line = SanitizeLine(buffer);

			if (!line.IsEmpty()) {
				if (!paragraph.IsEmpty()) {
					// if the previous line was very short, it
					//  must be intentional.  Keep a CR within
					//  the paragraph.
					if (prev_line_len < GP_MIN_LINE) {
						paragraph = paragraph + NL;
					} else {
						// if the prev line ended in a '-', we
						//  don't need to add a blank.  We don't
						//  remove the hyphen since it might be
						//  intentional and GP doesn't hyphenate
						//  very often.
						if (paragraph.Right(1) != "-")
							paragraph += " ";
					}
				}

				while (cr_count > 1) {
					paragraph += NL;
					cr_count--;
				}
				paragraph += line;
				prev_line_len = strlen(buffer);
				cr_count = 0;
			} else {
				end_paragraph = true;
				cr_count++;
			}
		}

		if (!paragraph.IsEmpty()) {
			section += paragraph + NL + NL;
			paragraph.Empty();
		}

		if ((cr_count >= 4) && (section.GetLength() >= MIN_SECTION_LEN)) {
			end_section = true;
		}
	}

	// write the section to a file
	if (!section.IsEmpty()) {
		// write the section to a file
		outfile.open(file_name);
		outfile << section << endl;
		outfile.close();
	}

	return ssource.eof();
}



void main (int argc, char *argv[])
{
	CString		source;
	CString		dest;
	CString		story;
	ifstream	ssource;
	boolean		done;
	
	if (argc != 4) {
		cout << "Syntax:  ParseGutenberg <source text> <dest root> <story name>" << endl;
		cout << "  where:  <source text> is the name of the source text file" << endl;
		cout << "          <dest root>   is the root name to be used for destination files" << endl;
		cout << "                        - a 2 digit number will be added" << endl;
		cout << "          <story name>  is the name of the story" << endl;
		return;
	} else {
		source = argv[1];
		dest = argv[2];
		story = argv[3];

		if (dest.GetLength() > 6) {
			dest = dest.Left(6);
			cout << "Destination root trimmed to: " << dest << endl;
		}
	}

	cout << "Processing:  " << source << endl;

	ssource.open(source, ios::in | ios::nocreate);
	if (!ssource.is_open()) {
		cout << "Failure opening:  " << source << endl;
		return;
	}

	done = false;
	for (int para_num=0;  !done;  para_num++) {
		done = ParseParagraph(ssource, dest, para_num);
		CreatePDB(dest, story, para_num);
	}

	return;
}