/*
 * Copyright @ 2000 Michael Arena
 * Do not change the contents od this file without consulting me:
 * arenamk@rcn.com
 */
#ifndef _FONTATTR_H
#define _FONTATTR_H

// Attributes Bits:
// +-----------+--------+------+------+-------+------+--------+-----------+
// | Attr Size |   Font Size   | Link | Fixed | Bold | Italic | Underline |
// | S = 0*    | ? = 0     0   |  0   |   0   |  0   |    0   |     0     |
// | L = 1     | S = 0     1   |  1   |   1   |  1   |    1   |     1     |
// |           | M = 1     0   |      |       |      |        |           |
// |           | L = 1     1   |      |       |      |        |           |
// +-----------+--------+------+------+-------+------+--------+-----------+

#define AttrSizeBit		0x80

#define FontSizeMask		0x60
#define FontSizeUnknown		0x00
#define FontSizeSmall		0x20
#define FontSizeMedium		0x40
#define FontSizeLarge		0x60

#define FontWidthFixed		0x08

#define FontLink		0x10

#define FontStyleMask		0x07
#define FontStyleBold		0x04
#define FontStyleItalic		0x02
#define FontStyleUnderline	0x01
#define FontStylePlain		0x00

#define FontStyleDefault	FontSizeMedium | FontStylePlain

#define IsAttrSizeLarge(b)	((b) & AttrSizeBit)
#define IsAttrSizeSmall(b)	!IsAttrSizeSmall(b)
#define SetAttrSizeLarge(b)	(b) |= AttrSizeBit
#define SetAttrSizeSmall(b)	(b) &= ~AttrSizeBit

#define IsFontSizeUnknown(b)	(((b) & FontSizeMask) == FontSizeUnknown)
#define IsFontSizeSmall(b)	(((b) & FontSizeMask) == FontSizeSmall)
#define IsFontSizeMedium(b)	(((b) & FontSizeMask) == FontSizeMedium)
#define IsFontSizeLarge(b)	(((b) & FontSizeMask) == FontSizeLarge)
//#define SetFontSizeUnknown(b)	b = ((b) & ~FontSizeMask) | FontSizeUnknown
#define SetFontSizeSmall(b)	b = ((b) & ~FontSizeMask) | FontSizeSmall
#define SetFontSizeMedium(b)	b = ((b) & ~FontSizeMask) | FontSizeMedium
#define SetFontSizeLarge(b)	b = ((b) & ~FontSizeMask) | FontSizeLarge

#define IsFontLink(b)		((b) & FontLink)
#define SetFontLink(b)		b |= FontLink
#define SetFontNoLink(b)	b &= ~FontLink

#define IsFontWidthFixed(b)	((b) & FontWidthFixed)
#define SetFontWidthFixed(b)	b |= FontWidthFixed
#define SetFontWidthNoFixed(b)	b &= ~FontWidthFixed

#define IsFontStyleBold(b)	((b) & FontStyleBold)
#define SetFontStyleBold(b)	b |= FontStyleBold
#define SetFontStyleNoBold(b)	b &= ~FontStyleBold

#define IsFontStyleItalic(b)	((b) & FontStyleItalic)
#define SetFontStyleItalic(b)	b |= FontStyleItalic
#define SetFontStyleNoItalic(b)	b &= ~FontStyleItalic

#define IsFontStyleUnderline(b)	((b) & FontStyleUnderline)
#define SetFontStyleUnderline(b) b |= FontStyleUnderline
#define SetFontStyleNoUnderline(b) b &= ~FontStyleUnderline

#define IsFontStylePlain(b)	(((b) & FontStyleMask) == FontStylePlain)
#define SetFontStylePlain(b)	b &= ~FontStyleMask


#define StdFont   0
#define BoldFont  1
#define LargeFont 2
#define NUMSYSFONTS  3

#define SmallFont 3
#define SmallIFont 4
#define FMedFont 5
#define NUMFONTS  6

// Attributes Bits:
// +-----------+-------+----+----+----+---+-----------------+-----------------+
// | Attr Size |  Arg  | Type             | Value                             |
// | S = 0     |  Size | 00 Justification | Left=0,Right=1,Justify=2,Center=3 |
// | L = 1*    | S = 0*| 01 reserved      |                                   |
// |           | L = 1 | 02 Anchor2       | 0=Normal,1=Hidden,2=EndHidden     |
// |           |       | 03 Horiz Line    | Filled=0,Empty=1                  |
// |           |       | 04 Red           | 0 (none) - 3 (max)                |
// |           |       | 05 Green         | 0 (none) - 3 (max)                |
// |           |       | 06 Blue          | 0 (none) - 3 (max)                |
// +-----------+-------+----+----+----+---+-----------------+-----------------+
// +-----------+-------+---------+--------+--------+--------+---------+-------+
// | Attr Size |  Arg  | Type             | Value                             |
// | S = 0     |  Size | 0 Left Indent    | 0 - 15                            |
// | L = 1*    | S = 0 | 1 Anchor         | 0 - 15                            |
// |           | L = 1*| 2 Hyperlink      | 0 - 15                            |
// |           |       | 3 First Indent   | -8 - 7                            |
// +-----------+-------+---------+--------+--------+--------+---------+-------+

#define ParAttrArgBit		0x40
#define ParAttrSmallTypeMask	0x3c
#define ParAttrSmallValueMask	0x03
#define ParAttrLargeTypeMask	0x30
#define ParAttrLargeValueMask	0x0f

// Small Arg Types
#define ParAttrTypeJustification 0x00
#define ParAttrTypeReserved	 0x04
#define ParAttrTypeAnchor2	 0x08
#define ParAttrTypeHorizLine	 0x0c
#define ParAttrTypeRed		 0x10
#define ParAttrTypeGreen	 0x14
#define ParAttrTypeBlue		 0x18
//#define ParAttrType??		 0x1c
//#define ParAttrType??		 0x20
//#define ParAttrType??		 0x24
//#define ParAttrType??		 0x28
//#define ParAttrType??		 0x2c
//#define ParAttrType??		 0x30
//#define ParAttrType??		 0x34
//#define ParAttrType??		 0x38
//#define ParAttrType??		 0x3c

// Large Arg Types
#define ParAttrTypeLeftIndent   0x00
#define ParAttrTypeAnchor	0x10
#define ParAttrTypeHyperlink	0x20
#define ParAttrTypeFirstIndent	0x30

#define ParAttrLeftJustification	0
#define ParAttrRightJustification	1
#define ParAttrJustifyJustification	2
#define ParAttrCenterJustification	3

#define ParAttrAnchorNormal		0
#define ParAttrAnchorHidden		1
#define ParAttrAnchorEndHidden		2

#define ParAttrHorizLineFilled		0
#define ParAttrHorizLineEmpty		1

#define IsParAttrLargeArg(b)	((b) & ParAttrArgBit)
#define IsParAttrSmallArg(b)	!IsParAttrLargeArg(b)
#define SetParAttrLargeArg(b)	(b) |= ParAttrArgBit
#define SetParAttrSmallArg(b)	(b) &= ~ParAttrArgBit

#define ParAttrSmallValue(b)	((b) & ParAttrSmallValueMask)
#define ParAttrLargeValue(b)	((b) & ParAttrLargeValueMask)

#define ParAttrSmallType(b)	((b) & ParAttrSmallTypeMask)
#define IsParAttrTypeJustification(b)\
 (ParAttrSmallType(b) == ParAttrTypeJustification)
#define SetParAttrTypeJustification(b,v)\
 b = 0x80 | ParAttrTypeJustification | ParAttrSmallValue(v)
#define IsParAttrTypeAnchor2(b)\
 (ParAttrSmallType(b) == ParAttrTypeAnchor2)
#define SetParAttrTypeAnchor2(b,v)\
 b = 0x80 | ParAttrTypeAnchor2 | ParAttrSmallValue(v)
#define IsParAttrTypeHorizLine(b)\
 (ParAttrSmallType(b) == ParAttrTypeHorizLine)
#define SetParAttrTypeHorizLine(b,v)\
 b = 0x80 | ParAttrTypeHorizLine | ParAttrSmallValue(v)
#define IsAttrTypeRed(b)\
 (ParAttrSmallType(b) == ParAttrTypeRed)
#define SetAttrTypeRed(b,v)\
 b = 0x80 | ParAttrTypeRed | ParAttrSmallValue(v)
#define IsAttrTypeGreen(b)\
 (ParAttrSmallType(b) == ParAttrTypeGreen)
#define SetAttrTypeGreen(b,v)\
 b = 0x80 | ParAttrTypeGreen | ParAttrSmallValue(v)
#define IsAttrTypeBlue(b)\
 (ParAttrSmallType(b) == ParAttrTypeBlue)
#define SetAttrTypeBlue(b,v)\
 b = 0x80 | ParAttrTypeBlue | ParAttrSmallValue(v)

#define ParAttrLargeType(b)	((b) & ParAttrLargeTypeMask)
#define IsParAttrTypeLeftIndent(b)\
 (ParAttrLargeType(b) == ParAttrTypeLeftIndent)
#define SetParAttrTypeLeftIndent(b,v)\
 b = 0x80 | ParAttrArgBit | ParAttrTypeLeftIndent | ParAttrLargeValue(v)
#define IsParAttrTypeAnchor(b)\
 (ParAttrLargeType(b) == ParAttrTypeAnchor)
#define SetParAttrTypeAnchor(b,v)\
 b = 0x80 | ParAttrArgBit | ParAttrTypeAnchor | ParAttrLargeValue(v)
#define IsParAttrTypeHyperlink(b)\
 (ParAttrLargeType(b) == ParAttrTypeHyperlink)
#define SetParAttrTypeHyperlink(b,v)\
 b = 0x80 | ParAttrArgBit | ParAttrTypeHyperlink | ParAttrLargeValue(v)
#define IsParAttrTypeFirstIndent(b)\
 (ParAttrLargeType(b) == ParAttrTypeFirstIndent)
#define SetParAttrTypeFirstIndent(b,v)\
 b = 0x80 | ParAttrArgBit | ParAttrTypeFirstIndent | ParAttrLargeValue(v)

#endif /* _FONTATTR_H */
