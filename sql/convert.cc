/* Copyright (C) 2000 MySQL AB & MySQL Finland AB & TCX DataKonsult AB

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA */


/*
** Convert tables between different character sets
** Some of the tables are hidden behind IFDEF to reduce some space.
** One can enable them by removing the // characters from the next comment
** One must also give a name to each mapping that one wants to use...
*/

/* #define DEFINE_ALL_CHARACTER_SETS */

#include "mysql_priv.h"

/****************************************************************************
  Convert tables
****************************************************************************/

/* Windows cp1251->koi8 and reverse conversion by Timur I. Bakeyev <translate@bat.ru> */
/* based on Russian-Apache Team tables by Dmitry M. Klimoff <dmk@kosnet.ru> */

static unsigned char cp1251_koi8[256] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,
144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,
160,161,162,163,164,189,166,167,179,169,180,171,172,173,174,183,
176,177,182,166,173,181,182,183,163,185,164,187,188,189,190,167,
225,226,247,231,228,229,246,250,233,234,235,236,237,238,239,240,
242,243,244,245,230,232,227,254,251,253,255,249,248,252,224,241,
193,194,215,199,196,197,214,218,201,202,203,204,205,206,207,208,
210,211,212,213,198,200,195,222,219,221,223,217,216,220,192,209
};

static unsigned char koi8_cp1251[256] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,
144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,
160,161,162,184,186,165,179,191,168,169,170,171,172,180,174,175,
176,177,178,168,170,181,178,175,184,185,186,187,188,165,190,191,
254,224,225,246,228,229,244,227,245,232,233,234,235,236,237,238,
239,255,240,241,242,243,230,226,252,251,231,248,253,249,247,250,
222,192,193,214,196,197,212,195,213,200,201,202,203,204,205,206,
207,223,208,209,210,211,198,194,220,219,199,216,221,217,215,218
};


#ifdef DEFINE_ALL_CHARACTER_SETS

/* These tables was generated from package 'cstools' (author Jan "Yenya" Kasprzak <kas@muni.cz>) */

/* Windows pc1250  to iso 8859-2 */

static unsigned char t1250_til2[256] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
128,129,  0,131,  0,  0,  0,  0,136,  0,169,  0,166,171,174,172,
144,  0,  0,  0,  0,  0,  0,  0,152,  0,185,  0,182,187,190,188,
160,183,162,163,164,161,  0,167,168,  0,170,  0,  0,173,  0,175,
176,  0,178,179,180,  0,  0,  0,184,177,186,  0,165,189,181,191,
192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,
208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,
224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,
240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255
};

static unsigned char til2_t1250[256] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
128,129,  0,131,  0,  0,  0,  0,136,  0,  0,  0,  0,  0,  0,  0,
144,  0,  0,  0,  0,  0,  0,  0,152,  0,  0,  0,  0,  0,  0,  0,
160,165,162,163,164,188,140,167,168,138,170,141,143,173,142,175,
176,185,178,179,180,190,156,161,184,154,186,157,159,189,158,191,
192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,
208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,
224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,
240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255
};

/* Windows pc1252  to iso 8859-2 */

static unsigned char t1252_til2[256] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
128,129,  0,  0,  0,  0,  0,  0,136,  0,169,  0,  0,141,142,143,
144,  0,  0,  0,  0,  0,  0,  0,189,  0,185,  0,  0,157,158,  0,
160,  0,  0,  0,164,  0,  0,167,168,  0,  0,  0,  0,173,  0,  0,
176,  0,  0,  0,180,  0,  0,  0,184,  0,  0,  0,  0,  0,  0,  0,
  0,193,194,  0,196,  0,  0,199,  0,201,  0,203,  0,205,206,  0,
208,  0,  0,211,212,  0,214,215,  0,  0,218,  0,220,221,  0,223,
  0,225,226,  0,228,  0,  0,231,  0,233,  0,235,  0,237,238,  0,
240,  0,  0,243,244,  0,246,247,  0,  0,250,  0,252,253,  0,  0
};
static unsigned char til2_t1252[256] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
128,129,  0,  0,  0,  0,  0,  0,136,  0,  0,  0,  0,141,142,143,
144,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,157,158,  0,
160,  0,  0,  0,164,  0,  0,167,168,138,  0,  0,  0,173,  0,  0,
176,  0,  0,  0,180,  0,  0,  0,184,154,  0,  0,  0,152,  0,  0,
  0,193,194,  0,196,  0,  0,199,  0,201,  0,203,  0,205,206,  0,
208,  0,  0,211,212,  0,214,215,  0,  0,218,  0,220,221,  0,223,
  0,225,226,  0,228,  0,  0,231,  0,233,  0,235,  0,237,238,  0,
240,  0,  0,243,244,  0,246,247,  0,  0,250,  0,252,253,  0,  0
};

/* MSDOS Kamenicky encoding (for Czech/Slovak) to iso 8859-2 */

static unsigned char tkam_til2[256] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
200,252,233,239,228,207,171,232,236,204,197,205,181,229,196,193,
201,190,174,244,246,211,249,218,253,214,220,169,165,221,216,187,
225,237,243,250,242,210,217,212,185,248,224,192,  0,167,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,247,  0,176,  0,  0,  0,  0,  0,  0,  0
};
static unsigned char til2_tkam[256] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,156,  0,173,  0,155,  0,134,  0,  0,146,  0,
248,  0,  0,  0,  0,140,  0,  0,  0,168,  0,159,  0,  0,145,  0,
171,143,  0,  0,142,138,  0,  0,128,144,  0,  0,137,139,  0,133,
  0,  0,165,149,167,  0,153,  0,158,166,151,  0,154,157,  0,  0,
170,160,  0,  0,132,141,  0,  0,135,130,  0,  0,136,161,  0,131,
  0,  0,164,162,147,  0,148,246,169,150,163,  0,129,152,  0,  0
};

/* Macintosh Roman encoding to iso 8859-2 */

static unsigned char tmac_til2[256] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
196,  0,199,201,  0,214,220,225,  0,226,228,  0,  0,231,233,  0,
  0,235,237,  0,238,  0,  0,243,  0,244,246,  0,250,  0,  0,252,
  0,176,  0,  0,167,  0,  0,223,  0,  0,  0,180,168,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,160,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,247,  0,  0,  0,  0,164,  0,  0,  0,  0,
  0,  0,  0,  0,  0,194,  0,193,203,  0,205,206,  0,  0,211,212,
  0,  0,218,  0,  0,  0,  0,  0,  0,162,255,  0,184,189,178,183
};
static unsigned char til2_tmac[256] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
202,  0,249,  0,219,  0,  0,164,172,  0,  0,  0,  0,  0,  0,  0,
161,  0,254,  0,171,  0,  0,255,252,  0,  0,  0,  0,253,  0,  0,
  0,231,229,  0,128,  0,  0,130,  0,131,  0,232,  0,234,235,  0,
  0,  0,  0,238,239,  0,133,  0,  0,  0,242,  0,134,  0,  0,167,
  0,135,137,  0,138,  0,  0,141,  0,142,  0,145,  0,146,148,  0,
  0,  0,  0,151,153,  0,154,214,  0,  0,156,  0,159,  0,  0,250
};

/* Macintosh Central European encodingto iso 8859-2 */

static unsigned char tmacce_til2[256] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
196,  0,  0,201,161,214,220,225,177,200,228,232,198,230,233,172,
188,207,237,239,  0,  0,  0,243,  0,244,246,  0,250,204,236,252,
  0,176,202,  0,167,  0,  0,223,  0,  0,  0,234,168,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,179,  0,  0,165,181,197,229,  0,
  0,209,  0,  0,241,210,  0,  0,  0,  0,160,242,213,  0,245,  0,
  0,  0,  0,  0,  0,  0,247,  0,  0,192,224,216,  0,  0,248,  0,
  0,169,  0,  0,185,166,182,193,171,187,205,174,190,  0,211,212,
  0,217,218,249,219,251,  0,  0,221,253,  0,175,163,191,  0,183
};
static unsigned char til2_tmacce[256] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
202,132,  0,252,  0,187,229,164,172,225,  0,232,143,  0,235,251,
161,136,  0,184,  0,188,230,255,  0,228,  0,233,144,  0,236,253,
217,231,  0,  0,128,189,140,  0,137,131,162,  0,157,234,  0,145,
  0,193,197,238,239,204,133,  0,219,241,242,244,134,248,  0,167,
218,135,  0,  0,138,190,141,  0,139,142,171,  0,158,146,  0,147,
  0,196,203,151,153,206,154,214,222,243,156,245,159,249,  0,  0
};

/* PC-Latin2 encoding, supported by M$-DOS to iso 8859-2 */

static unsigned char tpc2_til2[256] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
199,252,233,226,228,249,230,231,179,235,213,245,238,172,196,198,
201,197,229,244,246,165,181,166,182,214,220,171,187,163,215,232,
225,237,243,250,161,177,174,190,202,234,  0,188,200,186,  0,  0,
  0,  0,  0,  0,  0,193,194,204,170,  0,  0,  0,  0,175,191,  0,
  0,  0,  0,  0,  0,  0,195,227,  0,  0,  0,  0,  0,  0,  0,164,
240,208,207,203,239,210,205,206,236,  0,  0,  0,  0,222,217,  0,
211,223,212,209,241,242,169,185,192,218,224,219,253,221,254,180,
  0,189,178,183,162,167,247,184,  0,168,255,251,216,248,  0,  0
};
static unsigned char til2_tpc2[256] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,164,244,157,207,149,151,245,249,230,184,155,141,  0,166,189,
  0,165,242,136,239,150,152,243,247,231,173,156,171,241,167,190,
232,181,182,198,142,145,143,128,172,144,168,211,183,214,215,210,
209,227,213,224,226,138,153,158,252,222,233,235,154,237,221,225,
234,160,131,199,132,146,134,135,159,130,169,137,216,161,140,212,
208,228,229,162,147,139,148,246,253,133,163,251,129,236,238,250
};

/* Encoding used by standard IBM PC vga cards to iso8859-2 */
static unsigned char tvga_til2[256] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
199,252,233,226,228,  0,  0,231,  0,235,  0,  0,238,  0,196,  0,
201,  0,  0,244,246,  0,  0,  0,  0,214,220,  0,  0,  0,  0,  0,
225,237,243,250,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,247,  0,176,  0,  0,  0,  0,  0,  0,  0
};
static unsigned char til2_tvga[256] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
248,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,142,  0,  0,128,  0,144,  0,  0,  0,  0,  0,  0,
  0,  0,  0,  0,  0,  0,153,  0,  0,  0,  0,  0,154,  0,  0,  0,
  0,160,131,  0,132,  0,  0,135,  0,130,  0,137,  0,161,140,  0,
  0,  0,  0,162,147,  0,148,246,  0,  0,163,  0,129,  0,  0,  0
};

//Ukrainian koi8 and win1251 converting tables by Max Veremayenko
//(verem@tg.kiev.ua

static unsigned char koi8_ukr_win1251ukr[256] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,
144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,
160,161,162,184,186,165,179,191,168,169,170,171,172,180,174,175,
176,177,178,168,170,181,178,175,184,185,186,187,188,165,190,191,
254,224,225,246,228,229,244,227,245,232,233,234,235,236,237,238,
239,255,240,241,242,243,230,226,252,251,231,248,253,249,247,250,
222,192,193,214,196,197,212,195,213,200,201,202,203,204,205,206,
207,223,208,209,210,211,198,194,220,219,199,216,221,217,215,218
};

static unsigned char win1251ukr_koi8_ukr[256] = {
  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,
128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,
144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,
160,161,162,163,164,189,166,167,179,169,180,171,172,173,174,183,
176,177,182,166,173,181,182,183,163,185,164,187,188,189,190,167,
225,226,247,231,228,229,246,250,233,234,235,236,237,238,239,240,
242,243,244,245,230,232,227,254,251,253,255,249,248,252,224,241,
193,194,215,199,196,197,214,218,201,202,203,204,205,206,207,208,
210,211,212,213,198,200,195,222,219,221,223,217,216,220,192,209
};

#endif /* DEFINE_ALL_CHARACTER_SETS */

/****************************************************************************
** Declare mapping variables
****************************************************************************/


CONVERT conv_cp1251_koi8("cp1251_koi8", cp1251_koi8, koi8_cp1251, 1);
#ifdef DEFINE_ALL_CHARACTER_SETS
CONVERT conv_cp1250_latin2("cp1250_latin2", t1250_til2, til2_t1250, 2);
CONVERT conv_kam_latin2("kam_latin2", tkam_til2, til2_tkam, 3);
CONVERT conv_mac_latin2("mac_latin2", tmac_til2, til2_tmac, 4);
CONVERT conv_macce_latin2("macce_latin2", tmacce_til2, til2_tmacce, 5);
CONVERT conv_pc2_latin2("pc2_latin2", tpc2_til2, til2_tpc2, 6);
CONVERT conv_vga_latin2("vga_latin2", tvga_til2, til2_tvga, 7);
CONVERT conv_koi8_cp1251("koi8_cp1251", koi8_cp1251, cp1251_koi8, 8);
CONVERT conv_win1251ukr_koi8_ukr("win1251ukr_koi8_ukr", win1251ukr_koi8_ukr,
				 koi8_ukr_win1251ukr, 9);
CONVERT conv_koi8_ukr_win1251ukr("koi8_ukr_win1251ukr", koi8_ukr_win1251ukr,
				 win1251ukr_koi8_ukr, 10);
#endif /* DEFINE_ALL_CHARACTER_SETS */

CONVERT *convert_tables[]= {
  &conv_cp1251_koi8,
#ifdef DEFINE_ALL_CHARACTER_SETS
  &conv_cp1250_latin2,
  &conv_kam_latin2,
  &conv_mac_latin2,
  &conv_macce_latin2,
  &conv_pc2_latin2,
  &conv_vga_latin2,
  &conv_koi8_cp1251,
  &conv_win1251ukr_koi8_ukr,
  &conv_koi8_ukr_win1251ukr,
#endif /* DEFINE_ALL_CHARACTER_SETS */
  NULL
};


CONVERT *get_convert_set(const char *name)
{
  for (CONVERT **ptr=convert_tables ; *ptr ; ptr++)
  {
    /*
      BAR TODO: Monty's comments:
      Why is this using system_charset_info ?
      Isn't the character-set string given in the users default charset?
      Please add a TODO note to the code that this has to be fixed when the user
      will be able to cast strings to different character sets...
      The current code will also not work if/when we introduce support for
      16 bit characters...
      (I know that there is a LOT of changes to do if we ever want do this...)
    */
    if (!my_strcasecmp(system_charset_info,(*ptr)->name,name))
      return (*ptr);
  }
  return 0;
}


void CONVERT::convert_array(const uchar *map, uchar * buf, uint len)
{
  for (uchar *end=buf+len ; buf != end ; buf++)
    *buf= map[*buf];
}


/* This is identical as net_store_data, but with a conversion */

bool CONVERT::store(String *packet,const char *from,uint length)
{
  uint packet_length=packet->length();
  if (packet_length+5+length > packet->alloced_length() &&
      packet->realloc(packet_length+5+length))
    return 1;
  char *to=(char*) net_store_length((char*) packet->ptr()+packet_length,
				    (ulonglong)length);

  for (const char *end=from+length ; from != end ; from++)
    *to++= to_map[(uchar) *from];
  packet->length((uint) (to-packet->ptr()));
  return 0;
}

#ifdef EMBEDDED_LIBRARY
void CONVERT::convert_back(char *dest, const char *source, uint length) const
{
  for (char *end= dest+length; dest < end; dest++, source++)
    *dest= to_map[*source];
}
#endif

