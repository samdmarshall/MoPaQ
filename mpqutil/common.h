//
//  common.h
//  MoPaQ
//
//  Created by Sam Marshall on 4/25/14.
//  Copyright (c) 2014 Sam Marshall. All rights reserved.
//

#ifndef MoPaQ_common_h
#define MoPaQ_common_h

#include <stdint.h>

#define PACK __attribute__((packed))

struct mpq_common_magic {
	char magic[3];
	uint8_t offset;
} PACK;

struct mpq_common_header {
	struct mpq_common_magic magic;
	uint32_t version;
	uint32_t data_size;
} PACK;

struct mpq_common_table {
	uint32_t index_size_total;
	uint32_t index_size_extra;
	uint32_t index_size;
	uint32_t block_table_size;
} PACK;

enum Lang_Id {
	LANG_NEUTRAL = 0x00,
	LANG_INVARIANT = 0x7f,
	LANG_AFRIKAANS = 0x36,
	LANG_ALBANIAN = 0x1c,
	LANG_ALSATIAN = 0x84,
	LANG_AMHARIC = 0x5e,
	LANG_ARABIC = 0x01,
	LANG_ARMENIAN = 0x2b,
	LANG_ASSAMESE = 0x4d,
	LANG_AZERI = 0x2c,
	LANG_AZERBAIJANI = 0x2c,
	LANG_BANGLA = 0x45,
	LANG_BASHKIR = 0x6d,
	LANG_BASQUE = 0x2d,
	LANG_BELARUSIAN = 0x23,
	LANG_BENGALI = 0x45,
	LANG_BRETON = 0x7e,
	LANG_BOSNIAN = 0x1a,
	LANG_BOSNIAN_NEUTRAL = 0x781a,
	LANG_BULGARIAN = 0x02,
	LANG_CATALAN = 0x03,
	LANG_CENTRAL_KURDISH = 0x92,
	LANG_CHEROKEE = 0x5c,
	LANG_CHINESE = 0x04,
	LANG_CHINESE_SIMPLIFIED = 0x04,
	LANG_CHINESE_TRADITIONAL = 0x7c04,
	LANG_CORSICAN = 0x83,
	LANG_CROATIAN = 0x1a,
	LANG_CZECH = 0x05,
	LANG_DANISH = 0x06,
	LANG_DARI = 0x8c,
	LANG_DIVEHI = 0x65,
	LANG_DUTCH = 0x13,
	LANG_ENGLISH = 0x09,
	LANG_ESTONIAN = 0x25,
	LANG_FAEROESE = 0x38,
	LANG_FARSI = 0x29,
	LANG_FILIPINO = 0x64,
	LANG_FINNISH = 0x0b,
	LANG_FRENCH = 0x0c,
	LANG_FRISIAN = 0x62,
	LANG_FULAH = 0x67,
	LANG_GALICIAN = 0x56,
	LANG_GEORGIAN = 0x37,
	LANG_GERMAN = 0x07,
	LANG_GREEK = 0x08,
	LANG_GREENLANDIC = 0x6f,
	LANG_GUJARATI = 0x47,
	LANG_HAUSA = 0x68,
	LANG_HEBREW = 0x0d,
	LANG_HINDI = 0x39,
	LANG_HUNGARIAN = 0x0e,
	LANG_ICELANDIC = 0x0f,
	LANG_IGBO = 0x70,
	LANG_INDONESIAN = 0x21,
	LANG_INUKTITUT = 0x5d,
	LANG_IRISH = 0x3c,
	LANG_ITALIAN = 0x10,
	LANG_JAPANESE = 0x11,
	LANG_KANNADA = 0x4b,
	LANG_KASHMIRI = 0x60,
	LANG_KAZAK = 0x3f,
	LANG_KHMER = 0x53,
	LANG_KICHE = 0x86,
	LANG_KINYARWANDA = 0x87,
	LANG_KONKANI = 0x57,
	LANG_KOREAN = 0x12,
	LANG_KYRGYZ = 0x40,
	LANG_LAO = 0x54,
	LANG_LATVIAN = 0x26,
	LANG_LITHUANIAN = 0x27,
	LANG_LOWER_SORBIAN = 0x2e,
	LANG_LUXEMBOURGISH = 0x6e,
	LANG_MACEDONIAN = 0x2f,
	LANG_MALAY = 0x3e,
	LANG_MALAYALAM = 0x4c,
	LANG_MALTESE = 0x3a,
	LANG_MANIPURI = 0x58,
	LANG_MAORI = 0x81,
	LANG_MAPUDUNGUN = 0x7a,
	LANG_MARATHI = 0x4e,
	LANG_MOHAWK = 0x7c,
	LANG_MONGOLIAN = 0x50,
	LANG_NEPALI = 0x61,
	LANG_NORWEGIAN = 0x14,
	LANG_OCCITAN = 0x82,
	LANG_ODIA = 0x48,
	LANG_ORIYA = 0x48,
	LANG_PASHTO = 0x63,
	LANG_PERSIAN = 0x29,
	LANG_POLISH = 0x15,
	LANG_PORTUGUESE = 0x16,
	LANG_PULAR = 0x67,
	LANG_PUNJABI = 0x46,
	LANG_QUECHUA = 0x6b,
	LANG_ROMANIAN = 0x18,
	LANG_ROMANSH = 0x17,
	LANG_RUSSIAN = 0x19,
	LANG_SAKHA = 0x85,
	LANG_SAMI = 0x3b,
	LANG_SANSKRIT = 0x4f,
	LANG_SCOTTISH_GAELIC = 0x91,
	LANG_SERBIAN = 0x1a,
	LANG_SERBIAN_NEUTRAL = 0x7c1a,
	LANG_SINDHI = 0x59,
	LANG_SINHALESE = 0x5b,
	LANG_SLOVAK = 0x1b,
	LANG_SLOVENIAN = 0x24,
	LANG_SOTHO = 0x6c,
	LANG_SPANISH = 0x0a,
	LANG_SWAHILI = 0x41,
	LANG_SWEDISH = 0x1d,
	LANG_SYRIAC = 0x5a,
	LANG_TAJIK = 0x28,
	LANG_TAMAZIGHT = 0x5f,
	LANG_TAMIL = 0x49,
	LANG_TATAR = 0x44,
	LANG_TELUGU = 0x4a,
	LANG_THAI = 0x1e,
	LANG_TIBETAN = 0x51,
	LANG_TIGRIGNA = 0x73,
	LANG_TIGRINYA = 0x73,
	LANG_TSWANA = 0x32,
	LANG_TURKISH = 0x1f,
	LANG_TURKMEN = 0x42,
	LANG_UIGHUR = 0x80,
	LANG_UKRAINIAN = 0x22,
	LANG_UPPER_SORBIAN = 0x2e,
	LANG_URDU = 0x20,
	LANG_UZBEK = 0x43,
	LANG_VALENCIAN = 0x03,
	LANG_VIETNAMESE = 0x2a,
	LANG_WELSH = 0x52,
	LANG_WOLOF = 0x88,
	LANG_XHOSA = 0x34,
	LANG_YAKUT = 0x85,
	LANG_YI = 0x78,
	LANG_YORUBA = 0x6a,
	LANG_ZULU = 0x35
};

#define ConvertLangId(id) (id & 0x3ff)

#endif