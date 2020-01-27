/**
  Copyright (c) 2019 Vicente Romero Calero. All rights reserved.
  Licensed under the MIT License.
  See LICENSE file in the project root for full license information.
 */
#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "unit_tests.h"
#include "../../vtenc.h"

int test_vtenc_list_decode_u8_1(void)
{
  const uint8_t in[] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
  const size_t in_len = sizeof(in);
  size_t out_len = 1;
  uint8_t out[out_len];

  EXPECT_TRUE(vtenc_list_decode_u8(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_list_decode_u8_2(void)
{
  const uint8_t in[] = {0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  const size_t in_len = sizeof(in);
  size_t out_len = 4;
  uint8_t out[out_len];

  EXPECT_TRUE(vtenc_list_decode_u8(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_list_decode_u8_3(void)
{
  const uint8_t in[] = {0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e};
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_list_decoded_size_u8(in, in_len);
  uint8_t out[out_len];

  EXPECT_TRUE(vtenc_list_decode_u8(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_list_decode_u8_4(void)
{
  const uint8_t in[] = {
    0x0b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb0, 0x5a, 0xac, 0xb1, 0x74,
    0x80, 0x4b, 0x87, 0xc6, 0x01
  };
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_list_decoded_size_u8(in, in_len);
  uint8_t out[out_len];
  uint8_t expected[] = {5, 22, 23, 44, 62, 69, 109, 113, 178, 194, 206};

  EXPECT_TRUE(vtenc_list_decode_u8(in, in_len, out, out_len) == VtencErrorNoError);
  EXPECT_TRUE(out_len == 11);
  EXPECT_TRUE(memcmp(out, expected, sizeof(out)) == 0);

  return 1;
}

int test_vtenc_list_decode_u8_5(void)
{
  const uint8_t in[] = {
    0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6e, 0x00, 0x21, 0xc0, 0xe1,
    0x10, 0x08
  };
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_list_decoded_size_u8(in, in_len);
  uint8_t out[out_len];
  uint8_t expected[] = {57, 57, 57, 111, 111, 111, 111, 208, 208};

  EXPECT_TRUE(vtenc_list_decode_u8(in, in_len, out, out_len) == VtencErrorNoError);
  EXPECT_TRUE(out_len == 9);
  EXPECT_TRUE(memcmp(out, expected, sizeof(out)) == 0);

  return 1;
}

int test_vtenc_list_decode_u16_1(void)
{
  const uint8_t in[] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
  const size_t in_len = sizeof(in);
  size_t out_len = 1;
  uint16_t out[out_len];

  EXPECT_TRUE(vtenc_list_decode_u16(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_list_decode_u16_2(void)
{
  const uint8_t in[] = {0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  const size_t in_len = sizeof(in);
  size_t out_len = 4;
  uint16_t out[out_len];

  EXPECT_TRUE(vtenc_list_decode_u16(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_list_decode_u16_3(void)
{
  const uint8_t in[] = {0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e};
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_list_decoded_size_u16(in, in_len);
  uint16_t out[out_len];

  EXPECT_TRUE(vtenc_list_decode_u16(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_list_decode_u16_4(void)
{
  const uint8_t in[] = {
    0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xba, 0x66, 0x3b, 0x2a, 0xdf,
    0xac, 0x32, 0xee, 0x4c, 0xd7, 0x3d, 0x85, 0x30, 0x00
  };
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_list_decoded_size_u16(in, in_len);
  uint16_t out[out_len];
  uint16_t expected[] = {1099, 2227, 8102, 27654, 29001, 35511, 50083};

  EXPECT_TRUE(vtenc_list_decode_u16(in, in_len, out, out_len) == VtencErrorNoError);
  EXPECT_TRUE(out_len == 7);
  EXPECT_TRUE(memcmp(out, expected, sizeof(out)) == 0);

  return 1;
}

int test_vtenc_list_decode_u16_5(void)
{
  const uint8_t in[] = {
    0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0xe7, 0xde, 0x0b, 0x2e,
    0xb8, 0x60, 0x5c, 0x7a, 0x01
  };
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_list_decoded_size_u16(in, in_len);
  uint16_t out[out_len];
  uint16_t expected[] = {677, 677, 677, 8881, 8881, 8881, 8881, 8881};

  EXPECT_TRUE(vtenc_list_decode_u16(in, in_len, out, out_len) == VtencErrorNoError);
  EXPECT_TRUE(out_len == 8);
  EXPECT_TRUE(memcmp(out, expected, sizeof(out)) == 0);

  return 1;
}

int test_vtenc_list_decode_u32_1(void)
{
  const uint8_t in[] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
  const size_t in_len = sizeof(in);
  size_t out_len = 1;
  uint32_t out[out_len];

  EXPECT_TRUE(vtenc_list_decode_u32(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_list_decode_u32_2(void)
{
  const uint8_t in[] = {0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  const size_t in_len = sizeof(in);
  size_t out_len = 4;
  uint32_t out[out_len];

  EXPECT_TRUE(vtenc_list_decode_u32(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_list_decode_u32_3(void)
{
  const uint8_t in[] = {0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e};
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_list_decoded_size_u32(in, in_len);
  uint32_t out[out_len];

  EXPECT_TRUE(vtenc_list_decode_u32(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_list_decode_u32_4(void)
{
  const uint8_t in[] = {
    0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x9e, 0x37, 0xa7, 0x5b,
    0xbe, 0xff, 0xd5, 0x1a, 0xd2, 0x68, 0xa8, 0xfb, 0x74, 0x9d, 0xe7, 0x79,
    0xd2, 0x57, 0x01
  };
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_list_decoded_size_u32(in, in_len);
  uint32_t out[out_len];
  uint32_t expected[] = {5348, 13089333, 88199704, 271008013, 1451881090};

  EXPECT_TRUE(vtenc_list_decode_u32(in, in_len, out, out_len) == VtencErrorNoError);
  EXPECT_TRUE(out_len == 5);
  EXPECT_TRUE(memcmp(out, expected, sizeof(out)) == 0);

  return 1;
}

int test_vtenc_list_decode_u32_5(void)
{
  const uint8_t in[] = {
    0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6c, 0x93, 0x42, 0x42, 0x01,
    0x81, 0x94, 0x02, 0x42, 0x29, 0x05, 0x94, 0x50, 0x08, 0x21, 0x05, 0x04,
    0x02, 0x02, 0x01
  };
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_list_decoded_size_u32(in, in_len);
  uint32_t out[out_len];
  uint32_t expected[] = {77865901, 77865901, 77865901, 77865901, 314976310, 314976310};

  EXPECT_TRUE(vtenc_list_decode_u32(in, in_len, out, out_len) == VtencErrorNoError);
  EXPECT_TRUE(out_len == 6);
  EXPECT_TRUE(memcmp(out, expected, sizeof(out)) == 0);

  return 1;
}

int test_vtenc_list_decode_u64_1(void)
{
  const uint8_t in[] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
  const size_t in_len = sizeof(in);
  size_t out_len = 1;
  uint64_t out[out_len];

  EXPECT_TRUE(vtenc_list_decode_u64(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_list_decode_u64_2(void)
{
  const uint8_t in[] = {0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  const size_t in_len = sizeof(in);
  size_t out_len = 4;
  uint64_t out[out_len];

  EXPECT_TRUE(vtenc_list_decode_u64(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_list_decode_u64_3(void)
{
  const uint8_t in[] = {0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e};
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_list_decoded_size_u64(in, in_len);
  uint64_t out[out_len];

  EXPECT_TRUE(vtenc_list_decode_u64(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_list_decode_u64_4(void)
{
  const uint8_t in[] = {
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x48, 0x92, 0x24, 0x49, 0x92,
    0x24, 0xc9, 0xfd, 0xff, 0xfe, 0xfd, 0xfb, 0xa4, 0xaa, 0x22, 0xa2, 0x71,
    0xf3, 0xfd, 0x35, 0xd1, 0x0b, 0x95, 0xd6, 0xd0, 0x90, 0xe3, 0xb2
  };
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_list_decoded_size_u64(in, in_len);
  uint64_t out[out_len];
  uint64_t expected[] = {0x12a6, 0x8addf0, 0xffa1b4bb, 0x21258ee39aaa};

  EXPECT_TRUE(vtenc_list_decode_u64(in, in_len, out, out_len) == VtencErrorNoError);
  EXPECT_TRUE(out_len == 4);
  EXPECT_TRUE(memcmp(out, expected, sizeof(out)) == 0);

  return 1;
}

int test_vtenc_list_decode_u64_5(void)
{
  const uint8_t in[] = {
    0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xda, 0xb6, 0x6d, 0xdb, 0xb6,
    0x6d, 0xdb, 0x6e, 0x77, 0x67, 0x77, 0x67, 0x77, 0x67, 0x71, 0x61, 0x71,
    0x61, 0x71, 0x61, 0x71, 0x61, 0x71, 0x61, 0x71, 0x61, 0x71, 0x61, 0x71,
    0x01
  };
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_list_decoded_size_u64(in, in_len);
  uint64_t out[out_len];
  uint64_t expected[] = {0x55555555, 0x55555555, 0x55555555, 0x111111111111, 0x111111111111};

  EXPECT_TRUE(vtenc_list_decode_u64(in, in_len, out, out_len) == VtencErrorNoError);
  EXPECT_TRUE(out_len == 5);
  EXPECT_TRUE(memcmp(out, expected, sizeof(out)) == 0);

  return 1;
}

int test_vtenc_set_decode_u8_1(void)
{
  const uint8_t in[] = {0x00};
  const size_t in_len = sizeof(in);
  size_t out_len = 0;
  uint8_t out[out_len];

  EXPECT_TRUE(vtenc_set_decode_u8(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_set_decode_u8_2(void)
{
  const uint8_t in[] = {0x03, 0xff};
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_set_decoded_size_u8(in, in_len);
  uint8_t out[out_len];

  EXPECT_TRUE(vtenc_set_decode_u8(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_set_decode_u8_3(void)
{
  const uint8_t in[] = {0xff};
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_set_decoded_size_u8(in, in_len);
  uint8_t out[out_len];
  size_t expected_len = 256;
  uint8_t expected[expected_len];
  size_t i;

  for (i=0; i<expected_len; ++i) expected[i] = (uint8_t)i;

  EXPECT_TRUE(vtenc_set_decode_u8(in, in_len, out, out_len) == VtencErrorNoError);
  EXPECT_TRUE(out_len == expected_len);
  EXPECT_TRUE(memcmp(out, expected, sizeof(out)) == 0);

  return 1;
}

int test_vtenc_set_decode_u8_4(void)
{
  const uint8_t in[] = {0x0b, 0x88, 0x44, 0x20, 0x91, 0x04};
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_set_decoded_size_u8(in, in_len);
  uint8_t out[out_len];
  uint8_t expected[] = {0, 1, 2, 3, 4, 5, 6, 7, 160, 161, 162, 163};

  EXPECT_TRUE(vtenc_set_decode_u8(in, in_len, out, out_len) == VtencErrorNoError);
  EXPECT_TRUE(out_len == 12);
  EXPECT_TRUE(memcmp(out, expected, sizeof(out)) == 0);

  return 1;
}

int test_vtenc_set_decode_u8_5(void)
{
  const uint8_t in[] = {0x05, 0x4c, 0x7f, 0xc0, 0xc4, 0x4f, 0x02};
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_set_decoded_size_u8(in, in_len);
  uint8_t out[out_len];
  uint8_t expected[] = {13, 77, 88, 93, 149, 212};

  EXPECT_TRUE(vtenc_set_decode_u8(in, in_len, out, out_len) == VtencErrorNoError);
  EXPECT_TRUE(out_len == 6);
  EXPECT_TRUE(memcmp(out, expected, sizeof(out)) == 0);

  return 1;
}

int test_vtenc_set_decode_u16_1(void)
{
  const uint8_t in[] = {0x00, 0x00};
  const size_t in_len = sizeof(in);
  size_t out_len = 0;
  uint16_t out[out_len];

  EXPECT_TRUE(vtenc_set_decode_u16(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_set_decode_u16_2(void)
{
  const uint8_t in[] = {0x03, 0x00, 0xff};
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_set_decoded_size_u16(in, in_len);
  uint16_t out[out_len];

  EXPECT_TRUE(vtenc_set_decode_u16(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_set_decode_u16_3(void)
{
  const uint8_t in[] = {
    0x07, 0x00, 0xc6, 0x46, 0xe6, 0x6e, 0x6e, 0xab, 0xe6, 0x0f, 0x43, 0x1e,
    0xbe, 0x24, 0x74, 0x30, 0x5c
  };
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_set_decoded_size_u16(in, in_len);
  uint16_t out[out_len];
  uint16_t expected[] = {1655, 3391, 4111, 8770, 29006, 32712, 32993, 58042};

  EXPECT_TRUE(vtenc_set_decode_u16(in, in_len, out, out_len) == VtencErrorNoError);
  EXPECT_TRUE(out_len == 8);
  EXPECT_TRUE(memcmp(out, expected, sizeof(out)) == 0);

  return 1;
}

int test_vtenc_set_decode_u16_4(void)
{
  const uint8_t in[] = {
    0x0b, 0x00, 0x8c, 0x40, 0x20, 0x02, 0x00, 0x40, 0x02, 0x91, 0x00, 0x20,
    0x92
  };
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_set_decoded_size_u16(in, in_len);
  uint16_t out[out_len];
  uint16_t expected[] = {
    14000, 14001, 14002, 14003, 14004, 14005, 14006, 14007,
    20000, 20001, 20002, 20003
  };

  EXPECT_TRUE(vtenc_set_decode_u16(in, in_len, out, out_len) == VtencErrorNoError);
  EXPECT_TRUE(out_len == 12);
  EXPECT_TRUE(memcmp(out, expected, sizeof(out)) == 0);

  return 1;
}

int test_vtenc_set_decode_u32_1(void)
{
  const uint8_t in[] = {0x00, 0x00, 0x00, 0x00};
  const size_t in_len = sizeof(in);
  size_t out_len = 0;
  uint32_t out[out_len];

  EXPECT_TRUE(vtenc_set_decode_u32(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_set_decode_u32_2(void)
{
  const uint8_t in[] = {0x03, 0x00, 0x00, 0x00, 0xff};
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_set_decoded_size_u32(in, in_len);
  uint32_t out[out_len];

  EXPECT_TRUE(vtenc_set_decode_u32(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_set_decode_u32_3(void)
{
  const uint8_t in[] = {
    0x04, 0x00, 0x00, 0x00, 0x5c, 0x89, 0x7f, 0xc4, 0x29, 0x6f, 0xf7, 0x30,
    0xa4, 0x0e, 0x37, 0xf5, 0x61, 0xc3, 0x12, 0x76, 0x4a, 0x87, 0x9e, 0x03
  };
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_set_decoded_size_u32(in, in_len);
  uint32_t out[out_len];
  uint32_t expected[] = {0x98b204, 0x122fabb4, 0x378ecef0, 0x77ccab8f, 0xa40609bb};

  EXPECT_TRUE(vtenc_set_decode_u32(in, in_len, out, out_len) == VtencErrorNoError);
  EXPECT_TRUE(out_len == 5);
  EXPECT_TRUE(memcmp(out, expected, sizeof(out)) == 0);

  return 1;
}

int test_vtenc_set_decode_u32_4(void)
{
  const uint8_t in[] = {
    0x0d, 0x00, 0x00, 0x00, 0xee, 0xee, 0xee, 0xee, 0x46, 0xa0, 0x40, 0x81,
    0x00, 0x05, 0x02, 0x04, 0x00, 0x50, 0x00, 0x40, 0x80, 0x00, 0x04, 0x02,
    0x00, 0x28, 0x52, 0xa4, 0x48, 0x91, 0x22, 0x15
  };
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_set_decoded_size_u32(in, in_len);
  uint32_t out[out_len];
  uint32_t expected[] = {
    0xa500, 0xa501, 0xa502, 0xa503,
    0x4bbb00, 0x4bbb01,
    0xffff00, 0xffff01, 0xffff02, 0xffff03, 0xffff04, 0xffff05, 0xffff06, 0xffff07
  };

  EXPECT_TRUE(vtenc_set_decode_u32(in, in_len, out, out_len) == VtencErrorNoError);
  EXPECT_TRUE(out_len == 14);
  EXPECT_TRUE(memcmp(out, expected, sizeof(out)) == 0);

  return 1;
}

int test_vtenc_set_decode_u64_1(void)
{
  const uint8_t in[] = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
  const size_t in_len = sizeof(in);
  size_t out_len = 0;
  uint64_t out[out_len];

  EXPECT_TRUE(vtenc_set_decode_u64(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_set_decode_u64_2(void)
{
  const uint8_t in[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  const size_t in_len = sizeof(in);
  size_t out_len = 0;
  uint64_t out[out_len];

  EXPECT_TRUE(vtenc_set_decode_u64(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_set_decode_u64_3(void)
{
  const uint8_t in[] = {0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe};
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_set_decoded_size_u64(in, in_len);
  uint64_t out[out_len];

  EXPECT_TRUE(vtenc_set_decode_u64(in, in_len, out, out_len) == VtencErrorWrongFormat);

  return 1;
}

int test_vtenc_set_decode_u64_4(void)
{
  const uint8_t in[] = {
    0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xdb, 0x5a, 0x29, 0xad, 0x15, 0x32, 0x5d, 0xb2, 0xc7, 0xe6, 0xb3,
    0xb7, 0x0e, 0x0d, 0x41, 0xef, 0xd2, 0xb1, 0xb4, 0x0e, 0x8c, 0x70, 0xef,
    0xc2, 0xa9, 0xb7, 0x0a, 0x2e, 0x41, 0xaf, 0xe2, 0xb3, 0xb4, 0x08, 0xaf,
    0x70, 0x8f, 0xf2, 0xab, 0x03
  };
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_set_decoded_size_u64(in, in_len);
  uint64_t out[out_len];
  uint64_t expected[] = {
    0x11223344ULL, 0xaabbccddULL, 0x1010101010ULL, 0x5555555555ULL, 0xf0f0f0f0f0ULL,
    0x998877665544ULL, 0xffeeffeeffeeULL
  };

  EXPECT_TRUE(vtenc_set_decode_u64(in, in_len, out, out_len) == VtencErrorNoError);
  EXPECT_TRUE(out_len == 7);
  EXPECT_TRUE(memcmp(out, expected, sizeof(out)) == 0);

  return 1;
}

int test_vtenc_set_decode_u64_5(void)
{
  const uint8_t in[] = {
    0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x11, 0x11, 0x11, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0xcd, 0x5a, 0x6b, 0x2d,
    0xa5, 0x42, 0xa9, 0x54, 0x2a, 0x95, 0x4a, 0xa5, 0x52, 0xa9, 0x54, 0x2a,
    0x95, 0x4a, 0xa5, 0x52, 0xa9, 0x54, 0x2a, 0x95, 0x4a, 0xa5, 0x52, 0xa9,
    0x54, 0xaa, 0x02
  };
  const size_t in_len = sizeof(in);
  size_t out_len = vtenc_set_decoded_size_u64(in, in_len);
  uint64_t out[out_len];
  uint64_t expected[] = {
    0x20000000ULL, 0x20000001ULL, 0x20000002ULL, 0x20000003ULL,
    0x80000000ULL, 0x80000001ULL,
    0x2000000000ULL, 0x2000000001ULL
  };

  EXPECT_TRUE(vtenc_set_decode_u64(in, in_len, out, out_len) == VtencErrorNoError);
  EXPECT_TRUE(out_len == 8);
  EXPECT_TRUE(memcmp(out, expected, sizeof(out)) == 0);

  return 1;
}

int test_vtenc_list_decoded_size_1(void)
{
  const uint8_t in[] = {};
  const size_t in_len = sizeof(in);

  EXPECT_TRUE(vtenc_list_decoded_size_u8(in, in_len) == 0);
  EXPECT_TRUE(vtenc_list_decoded_size_u16(in, in_len) == 0);
  EXPECT_TRUE(vtenc_list_decoded_size_u32(in, in_len) == 0);
  EXPECT_TRUE(vtenc_list_decoded_size_u64(in, in_len) == 0);

  return 1;
}

int test_vtenc_list_decoded_size_2(void)
{
  const uint8_t in[] = {0xff, 0xff};
  const size_t in_len = sizeof(in);

  EXPECT_TRUE(vtenc_list_decoded_size_u8(in, in_len) == 0);
  EXPECT_TRUE(vtenc_list_decoded_size_u16(in, in_len) == 0);
  EXPECT_TRUE(vtenc_list_decoded_size_u32(in, in_len) == 0);
  EXPECT_TRUE(vtenc_list_decoded_size_u64(in, in_len) == 0);

  return 1;
}

int test_vtenc_list_decoded_size_3(void)
{
  const uint8_t in[] = {0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  const size_t in_len = sizeof(in);

  EXPECT_TRUE(vtenc_list_decoded_size_u8(in, in_len) == 7);
  EXPECT_TRUE(vtenc_list_decoded_size_u16(in, in_len) == 7);
  EXPECT_TRUE(vtenc_list_decoded_size_u32(in, in_len) == 7);
  EXPECT_TRUE(vtenc_list_decoded_size_u64(in, in_len) == 7);

  return 1;
}

int test_vtenc_list_decoded_size_4(void)
{
  const uint8_t in[] = {0xff, 0xff, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00};
  const size_t in_len = sizeof(in);

  EXPECT_TRUE(vtenc_list_decoded_size_u8(in, in_len) == 1048575);
  EXPECT_TRUE(vtenc_list_decoded_size_u16(in, in_len) == 1048575);
  EXPECT_TRUE(vtenc_list_decoded_size_u32(in, in_len) == 1048575);
  EXPECT_TRUE(vtenc_list_decoded_size_u64(in, in_len) == 1048575);

  return 1;
}

int test_vtenc_set_decoded_size_with_wrong_input(void)
{
  const uint8_t in[] = {};
  const size_t in_len = sizeof(in);

  EXPECT_TRUE(vtenc_set_decoded_size_u8(in, in_len) == 0);
  EXPECT_TRUE(vtenc_set_decoded_size_u16(in, in_len) == 0);
  EXPECT_TRUE(vtenc_set_decoded_size_u32(in, in_len) == 0);
  EXPECT_TRUE(vtenc_set_decoded_size_u64(in, in_len) == 0);

  return 1;
}

int test_vtenc_set_decoded_size_u8(void)
{
  const uint8_t *in;
  const size_t in_len = 1;

  in = (const uint8_t *)"\x00"; EXPECT_TRUE(vtenc_set_decoded_size_u8(in, in_len) == 1);
  in = (const uint8_t *)"\x05"; EXPECT_TRUE(vtenc_set_decoded_size_u8(in, in_len) == 6);
  in = (const uint8_t *)"\x34"; EXPECT_TRUE(vtenc_set_decoded_size_u8(in, in_len) == 53);
  in = (const uint8_t *)"\xb3"; EXPECT_TRUE(vtenc_set_decoded_size_u8(in, in_len) == 180);
  in = (const uint8_t *)"\xff"; EXPECT_TRUE(vtenc_set_decoded_size_u8(in, in_len) == 256);

  return 1;
}

int test_vtenc_set_decoded_size_u16(void)
{
  const uint8_t *in;
  const size_t in_len = 2;

  in = (const uint8_t *)"\x00\x00"; EXPECT_TRUE(vtenc_set_decoded_size_u16(in, in_len) == 1);
  in = (const uint8_t *)"\x01\x01"; EXPECT_TRUE(vtenc_set_decoded_size_u16(in, in_len) == 258);
  in = (const uint8_t *)"\x25\x33"; EXPECT_TRUE(vtenc_set_decoded_size_u16(in, in_len) == 13094);
  in = (const uint8_t *)"\x00\xff"; EXPECT_TRUE(vtenc_set_decoded_size_u16(in, in_len) == 65281);
  in = (const uint8_t *)"\xff\xff"; EXPECT_TRUE(vtenc_set_decoded_size_u16(in, in_len) == 65536);

  return 1;
}

int test_vtenc_set_decoded_size_u32(void)
{
  const uint8_t *in;
  const size_t in_len = 4;

  in = (const uint8_t *)"\x00\x00\x00\x00"; EXPECT_TRUE(vtenc_set_decoded_size_u32(in, in_len) == 1);
  in = (const uint8_t *)"\x01\x01\x01\x01"; EXPECT_TRUE(vtenc_set_decoded_size_u32(in, in_len) == 16843010);
  in = (const uint8_t *)"\x55\x55\x55\x55"; EXPECT_TRUE(vtenc_set_decoded_size_u32(in, in_len) == 1431655766);
  in = (const uint8_t *)"\x00\xff\xff\x00"; EXPECT_TRUE(vtenc_set_decoded_size_u32(in, in_len) == 16776961);
  in = (const uint8_t *)"\xff\xff\xff\xff"; EXPECT_TRUE(vtenc_set_decoded_size_u32(in, in_len) == 4294967296);

  return 1;
}

int test_vtenc_set_decoded_size_u64(void)
{
  const uint8_t *in;
  const size_t in_len = 8;

  in = (const uint8_t *)"\x00\x00\x00\x00\x00\x00\x00\x00"; EXPECT_TRUE(vtenc_set_decoded_size_u64(in, in_len) == 1);
  in = (const uint8_t *)"\x01\x01\x01\x01\x01\x01\x01\x01"; EXPECT_TRUE(vtenc_set_decoded_size_u64(in, in_len) == 0x0101010101010102ULL);
  in = (const uint8_t *)"\x55\x55\x55\x55\x55\x55\x55\x55"; EXPECT_TRUE(vtenc_set_decoded_size_u64(in, in_len) == 0x0155555555555556ULL);
  in = (const uint8_t *)"\x00\xff\xff\x00\x00\xff\xff\x00"; EXPECT_TRUE(vtenc_set_decoded_size_u64(in, in_len) == 0x00ffff0000ffff01ULL);
  in = (const uint8_t *)"\xff\xff\xff\xff\xff\xff\xff\xff"; EXPECT_TRUE(vtenc_set_decoded_size_u64(in, in_len) == 0x0200000000000000ULL);

  return 1;
}
