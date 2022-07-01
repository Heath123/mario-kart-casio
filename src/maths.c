#include "./maths.h"

#define angleWidth 192

// const short lut[91] = {
//   0, 572, 1144, 1715, 2286, 2856, 3425, 3993, 4560, 5126, 5690, 6252, 6813, 7371, 7927, 8481, 9032, 9580, 10126, 10668, 11207, 11743, 12275, 12803, 13328, 13848, 14364, 14876, 15383, 15886, 16383, 16876, 17364, 17846, 18323, 18794, 19260, 19720, 20173, 20621, 21062, 21497, 21925, 22347, 22762, 23170, 23571, 23964, 24351, 24730, 25101, 25465, 25821, 26169, 26509, 26841, 27165, 27481, 27788, 28087, 28377, 28659, 28932, 29196, 29451, 29697, 29934, 30162, 30381, 30591, 30791, 30982, 31163, 31335, 31498, 31650, 31794, 31927, 32051, 32165, 32269, 32364, 32448, 32523, 32587, 32642, 32687, 32722, 32747, 32762, 32767
// };

const short lut[angleWidth] = {
  0, 269, 539, 808, 1078, 1347, 1616, 1885, 2154, 2423, 2692, 2960, 3228, 3497, 3764, 4032, 4299, 4566, 4833, 5099, 5365, 5631, 5896, 6161, 6426, 6690, 6953, 7216, 7479, 7741, 8003, 8264, 8524, 8784, 9043, 9302, 9560, 9818, 10074, 10330, 10586, 10840, 11094, 11348, 11600, 11852, 12102, 12352, 12602, 12850, 13097, 13344, 13590, 13834, 14078, 14321, 14563, 14804, 15044, 15283, 15520, 15757, 15993, 16228, 16461, 16694, 16925, 17155, 17384, 17612, 17839, 18064, 18288, 18511, 18733, 18953, 19173, 19391, 19607, 19822, 20036, 20249, 20460, 20670, 20878, 21085, 21291, 21495, 21697, 21899, 22098, 22297, 22493, 22689, 22882, 23074, 23265, 23454, 23641, 23827, 24011, 24194, 24375, 24554, 24732, 24907, 25082, 25254, 25425, 25594, 25762, 25927, 26091, 26253, 26414, 26572, 26729, 26884, 27037, 27188, 27338, 27486, 27631, 27775, 27917, 28057, 28196, 28332, 28466, 28599, 28730, 28858, 28985, 29109, 29232, 29353, 29472, 29589, 29703, 29816, 29927, 30036, 30142, 30247, 30350, 30450, 30549, 30645, 30739, 30832, 30922, 31010, 31096, 31180, 31262, 31341, 31419, 31494, 31568, 31639, 31708, 31775, 31839, 31902, 31963, 32021, 32077, 32131, 32183, 32232, 32280, 32325, 32368, 32409, 32447, 32484, 32518, 32550, 32580, 32608, 32633, 32656, 32677, 32696, 32713, 32727, 32739, 32749, 32757, 32763, 32766, 32767
};

short fpsin(short x) {
  x = x % ((angleWidth - 1) * 4);
  if (x < 0) {
    x += ((angleWidth - 1) * 4);
  }
  short sign = 1;
  if (x < ((angleWidth - 1) * 2)) {
    sign = 1;
  } else {
    sign = -1;
  }
  x = x % ((angleWidth - 1) * 2);
  if (x > (angleWidth - 1)) {
    x = ((angleWidth - 1) * 2) - x;
  }
  return lut[x] * sign;
}

/*
const short lut[angleWidth * 4] = {
  0, 269, 539, 808, 1078, 1347, 1616, 1885, 2154, 2423, 2692, 2960, 3228, 3497, 3764, 4032, 4299, 4566, 4833, 5099, 5365, 5631, 5896, 6161, 6426, 6690, 6953, 7216, 7479, 7741, 8003, 8264, 8524, 8784, 9043, 9302, 9560, 9818, 10074, 10330, 10586, 10840, 11094, 11348, 11600, 11852, 12102, 12352, 12602, 12850, 13097, 13344, 13590, 13834, 14078, 14321, 14563, 14804, 15044, 15283, 15520, 15757, 15993, 16228, 16461, 16694, 16925, 17155, 17384, 17612, 17839, 18064, 18288, 18511, 18733, 18953, 19173, 19391, 19607, 19822, 20036, 20249, 20460, 20670, 20878, 21085, 21291, 21495, 21697, 21899, 22098, 22297, 22493, 22689, 22882, 23074, 23265, 23454, 23641, 23827, 24011, 24194, 24375, 24554, 24732, 24907, 25082, 25254, 25425, 25594, 25762, 25927, 26091, 26253, 26414, 26572, 26729, 26884, 27037, 27188, 27338, 27486, 27631, 27775, 27917, 28057, 28196, 28332, 28466, 28599, 28730, 28858, 28985, 29109, 29232, 29353, 29472, 29589, 29703, 29816, 29927, 30036, 30142, 30247, 30350, 30450, 30549, 30645, 30739, 30832, 30922, 31010, 31096, 31180, 31262, 31341, 31419, 31494, 31568, 31639, 31708, 31775, 31839, 31902, 31963, 32021, 32077, 32131, 32183, 32232, 32280, 32325, 32368, 32409, 32447, 32484, 32518, 32550, 32580, 32608, 32633, 32656, 32677, 32696, 32713, 32727, 32739, 32749, 32757, 32763, 32766, 32767, 32766, 32763, 32757, 32749, 32739, 32727, 32713, 32696, 32677, 32656, 32633, 32608, 32580, 32550, 32518, 32484, 32447, 32409, 32368, 32325, 32280, 32232, 32183, 32131, 32077, 32021, 31963, 31902, 31839, 31775, 31708, 31639, 31568, 31494, 31419, 31341, 31262, 31180, 31096, 31010, 30922, 30832, 30739, 30645, 30549, 30450, 30350, 30247, 30142, 30036, 29927, 29816, 29703, 29589, 29472, 29353, 29232, 29109, 28985, 28858, 28730, 28599, 28466, 28332, 28196, 28057, 27917, 27775, 27631, 27486, 27338, 27188, 27037, 26884, 26729, 26572, 26414, 26253, 26091, 25927, 25762, 25594, 25425, 25254, 25082, 24907, 24732, 24554, 24375, 24194, 24011, 23827, 23641, 23454, 23265, 23074, 22882, 22689, 22493, 22297, 22098, 21899, 21697, 21495, 21291, 21085, 20878, 20670, 20460, 20249, 20036, 19822, 19607, 19391, 19173, 18953, 18733, 18511, 18288, 18064, 17839, 17612, 17384, 17155, 16925, 16694, 16461, 16228, 15993, 15757, 15520, 15283, 15044, 14804, 14563, 14321, 14078, 13834, 13590, 13344, 13097, 12850, 12602, 12352, 12102, 11852, 11600, 11348, 11094, 10840, 10586, 10330, 10074, 9818, 9560, 9302, 9043, 8784, 8524, 8264, 8003, 7741, 7479, 7216, 6953, 6690, 6426, 6161, 5896, 5631, 5365, 5099, 4833, 4566, 4299, 4032, 3764, 3497, 3228, 2960, 2692, 2423, 2154, 1885, 1616, 1347, 1078, 808, 539, 269, 0, -269, -539, -808, -1078, -1347, -1616, -1885, -2154, -2423, -2692, -2960, -3228, -3497, -3764, -4032, -4299, -4566, -4833, -5099, -5365, -5631, -5896, -6161, -6426, -6690, -6953, -7216, -7479, -7741, -8003, -8264, -8524, -8784, -9043, -9302, -9560, -9818, -10074, -10330, -10586, -10840, -11094, -11348, -11600, -11852, -12102, -12352, -12602, -12850, -13097, -13344, -13590, -13834, -14078, -14321, -14563, -14804, -15044, -15283, -15520, -15757, -15993, -16228, -16461, -16694, -16925, -17155, -17384, -17612, -17839, -18064, -18288, -18511, -18733, -18953, -19173, -19391, -19607, -19822, -20036, -20249, -20460, -20670, -20878, -21085, -21291, -21495, -21697, -21899, -22098, -22297, -22493, -22689, -22882, -23074, -23265, -23454, -23641, -23827, -24011, -24194, -24375, -24554, -24732, -24907, -25082, -25254, -25425, -25594, -25762, -25927, -26091, -26253, -26414, -26572, -26729, -26884, -27037, -27188, -27338, -27486, -27631, -27775, -27917, -28057, -28196, -28332, -28466, -28599, -28730, -28858, -28985, -29109, -29232, -29353, -29472, -29589, -29703, -29816, -29927, -30036, -30142, -30247, -30350, -30450, -30549, -30645, -30739, -30832, -30922, -31010, -31096, -31180, -31262, -31341, -31419, -31494, -31568, -31639, -31708, -31775, -31839, -31902, -31963, -32021, -32077, -32131, -32183, -32232, -32280, -32325, -32368, -32409, -32447, -32484, -32518, -32550, -32580, -32608, -32633, -32656, -32677, -32696, -32713, -32727, -32739, -32749, -32757, -32763, -32766, -32767, -32766, -32763, -32757, -32749, -32739, -32727, -32713, -32696, -32677, -32656, -32633, -32608, -32580, -32550, -32518, -32484, -32447, -32409, -32368, -32325, -32280, -32232, -32183, -32131, -32077, -32021, -31963, -31902, -31839, -31775, -31708, -31639, -31568, -31494, -31419, -31341, -31262, -31180, -31096, -31010, -30922, -30832, -30739, -30645, -30549, -30450, -30350, -30247, -30142, -30036, -29927, -29816, -29703, -29589, -29472, -29353, -29232, -29109, -28985, -28858, -28730, -28599, -28466, -28332, -28196, -28057, -27917, -27775, -27631, -27486, -27338, -27188, -27037, -26884, -26729, -26572, -26414, -26253, -26091, -25927, -25762, -25594, -25425, -25254, -25082, -24907, -24732, -24554, -24375, -24194, -24011, -23827, -23641, -23454, -23265, -23074, -22882, -22689, -22493, -22297, -22098, -21899, -21697, -21495, -21291, -21085, -20878, -20670, -20460, -20249, -20036, -19822, -19607, -19391, -19173, -18953, -18733, -18511, -18288, -18064, -17839, -17612, -17384, -17155, -16925, -16694, -16461, -16228, -15993, -15757, -15520, -15283, -15044, -14804, -14563, -14321, -14078, -13834, -13590, -13344, -13097, -12850, -12602, -12352, -12102, -11852, -11600, -11348, -11094, -10840, -10586, -10330, -10074, -9818, -9560, -9302, -9043, -8784, -8524, -8264, -8003, -7741, -7479, -7216, -6953, -6690, -6426, -6161, -5896, -5631, -5365, -5099, -4833, -4566, -4299, -4032, -3764, -3497, -3228, -2960, -2692, -2423, -2154, -1885, -1616, -1347, -1078, -808, -539, -269, 0
};

short fpsin(short x) {
  x = x % ((angleWidth - 1) * 4);
  return lut[x];
}
*/

short fpcos(short x) {
  return fpsin(x + angleWidth);
}
