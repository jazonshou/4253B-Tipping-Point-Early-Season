#include "main.h"

// std::vector<std::vector<double>> AWP::fwdRLeft = {
//         {0},
//         {-0.0271},
//         {-0.0758},
//         {-0.1254},
//         {-0.1753},
//         {-0.2252},
//         {-0.2751},
//         {-0.3251},
//         {-0.3751},
//         {-0.4251},
//         {-0.475},
//         {-0.525},
//         {-0.575},
//         {-0.625},
//         {-0.6751},
//         {-0.7251},
//         {-0.775},
//         {-0.825},
//         {-0.875},
//         {-0.925},
//         {-0.975},
//         {-1.025},
//         {-1.075},
//         {-1.125},
//         {-1.175},
//         {-1.225},
//         {-1.275},
//         {-1.325},
//         {-1.375},
//         {-1.425},
//         {-1.475},
//         {-1.525},
//         {-1.575},
//         {-1.625},
//         {-1.675},
//         {-1.725},
//         {-1.775},
//         {-1.825},
//         {-1.875},
//         {-1.9213},
//         {-1.8979},
//         {-1.8479},
//         {-1.7979},
//         {-1.7479},
//         {-1.6979},
//         {-1.6479},
//         {-1.5979},
//         {-1.5479},
//         {-1.4979},
//         {-1.4479},
//         {-1.3979},
//         {-1.3478},
//         {-1.2978},
//         {-1.2478},
//         {-1.1978},
//         {-1.1478},
//         {-1.0978},
//         {-1.0478},
//         {-0.9978},
//         {-0.9478},
//         {-0.8978},
//         {-0.8478},
//         {-0.7978},
//         {-0.7478},
//         {-0.6978},
//         {-0.6477},
//         {-0.5978},
//         {-0.5478},
//         {-0.4978},
//         {-0.4477},
//         {-0.3977},
//         {-0.3477},
//         {-0.2977},
//         {-0.2476},
//         {-0.1975},
//         {-0.1475},
//         {-0.0975},
//         {-0.0473}
//     }
// ;
// std::vector<std::vector<double>> AWP::fwdRRight = {
//         {0},
//         {-0.0271},
//         {-0.0758},
//         {-0.1254},
//         {-0.1753},
//         {-0.2252},
//         {-0.2751},
//         {-0.3251},
//         {-0.3751},
//         {-0.4251},
//         {-0.475},
//         {-0.525},
//         {-0.575},
//         {-0.625},
//         {-0.6751},
//         {-0.7251},
//         {-0.775},
//         {-0.825},
//         {-0.875},
//         {-0.925},
//         {-0.975},
//         {-1.025},
//         {-1.075},
//         {-1.125},
//         {-1.175},
//         {-1.225},
//         {-1.275},
//         {-1.325},
//         {-1.375},
//         {-1.425},
//         {-1.475},
//         {-1.525},
//         {-1.575},
//         {-1.625},
//         {-1.675},
//         {-1.725},
//         {-1.775},
//         {-1.825},
//         {-1.875},
//         {-1.9213},
//         {-1.8979},
//         {-1.8479},
//         {-1.7979},
//         {-1.7479},
//         {-1.6979},
//         {-1.6479},
//         {-1.5979},
//         {-1.5479},
//         {-1.4979},
//         {-1.4479},
//         {-1.3979},
//         {-1.3478},
//         {-1.2978},
//         {-1.2478},
//         {-1.1978},
//         {-1.1478},
//         {-1.0978},
//         {-1.0478},
//         {-0.9978},
//         {-0.9478},
//         {-0.8978},
//         {-0.8478},
//         {-0.7978},
//         {-0.7478},
//         {-0.6978},
//         {-0.6477},
//         {-0.5978},
//         {-0.5478},
//         {-0.4978},
//         {-0.4477},
//         {-0.3977},
//         {-0.3477},
//         {-0.2977},
//         {-0.2476},
//         {-0.1975},
//         {-0.1475},
//         {-0.0975},
//         {-0.0473}
//     }
// ;

// std::vector<std::vector<double>> AWP:: loopbackLeft = {
//         {0},
//         {0.0335},
//         {0.0903},
//         {0.151},
//         {0.2127},
//         {0.2763},
//         {0.3386},
//         {0.4005},
//         {0.4643},
//         {0.5278},
//         {0.5904},
//         {0.6546},
//         {0.7183},
//         {0.7832},
//         {0.8475},
//         {0.9127},
//         {0.978},
//         {1.045},
//         {1.1104},
//         {1.1786},
//         {1.2456},
//         {1.3147},
//         {1.3836},
//         {1.4534},
//         {1.525},
//         {1.5962},
//         {1.67},
//         {1.7438},
//         {1.819},
//         {1.896},
//         {1.9745},
//         {2.0535},
//         {2.1353},
//         {2.2185},
//         {2.3043},
//         {2.3912},
//         {2.4816},
//         {2.5741},
//         {2.6694},
//         {2.7677},
//         {2.8693},
//         {2.9739},
//         {3.0835},
//         {3.1959},
//         {3.3127},
//         {3.4354},
//         {3.5617},
//         {3.6364},
//         {3.6354},
//         {3.6209},
//         {3.6075},
//         {3.5973},
//         {3.5872},
//         {3.5785},
//         {3.5727},
//         {3.5658},
//         {3.5632},
//         {3.5583},
//         {3.5551},
//         {3.5544},
//         {3.5526},
//         {3.5522},
//         {3.5506},
//         {3.5527},
//         {3.551},
//         {3.5528},
//         {3.5532},
//         {3.5537},
//         {3.5552},
//         {3.5568},
//         {3.5569},
//         {3.5588},
//         {3.5601},
//         {3.5624},
//         {3.5642},
//         {3.5656},
//         {3.5698},
//         {3.5731},
//         {3.5756},
//         {3.5825},
//         {3.5868},
//         {3.5936},
//         {3.6023},
//         {3.6111},
//         {3.6222},
//         {3.635},
//         {3.6492},
//         {3.6661},
//         {3.6843},
//         {3.7045},
//         {3.7225},
//         {3.7383},
//         {3.7517},
//         {3.7635},
//         {3.7743},
//         {3.7836},
//         {3.7914},
//         {3.7974},
//         {3.8036},
//         {3.8073},
//         {3.8095},
//         {3.7412},
//         {3.6203},
//         {3.4979},
//         {3.3786},
//         {3.2623},
//         {3.148},
//         {3.036},
//         {2.9243},
//         {2.8139},
//         {2.7027},
//         {2.6575},
//         {3.4699},
//         {3.6647},
//         {3.6494},
//         {3.6373},
//         {3.6266},
//         {3.6173},
//         {3.6091},
//         {3.6021},
//         {3.5962},
//         {3.5892},
//         {3.585},
//         {3.5836},
//         {3.5789},
//         {3.5769},
//         {3.5755},
//         {3.5747},
//         {3.5743},
//         {3.5722},
//         {3.5727},
//         {3.5757},
//         {3.5748},
//         {3.5765},
//         {3.5786},
//         {3.581},
//         {3.5819},
//         {3.5873},
//         {3.5892},
//         {3.5938},
//         {3.5989},
//         {3.6048},
//         {3.6115},
//         {3.619},
//         {3.6257},
//         {3.6353},
//         {3.646},
//         {3.6597},
//         {3.6696},
//         {3.686},
//         {3.7022},
//         {3.7186},
//         {3.7383},
//         {3.7613},
//         {3.7818},
//         {3.81},
//         {3.8325},
//         {3.8593},
//         {3.8825},
//         {3.9037},
//         {3.9269},
//         {3.9485},
//         {3.971},
//         {3.9912},
//         {4.0126},
//         {4.0363},
//         {4.0561},
//         {4.0802},
//         {4.101},
//         {4.126},
//         {4.1487},
//         {4.1738},
//         {4.1978},
//         {4.2241},
//         {4.2309},
//         {4.2034},
//         {4.1723},
//         {4.1417},
//         {4.1148},
//         {4.0895},
//         {4.0632},
//         {4.0413},
//         {4.0194},
//         {3.9982},
//         {3.9787},
//         {3.9596},
//         {3.9431},
//         {3.9255},
//         {3.9101},
//         {3.8946},
//         {3.8808},
//         {3.8668},
//         {3.8538},
//         {3.8415},
//         {3.8297},
//         {3.8185},
//         {3.8077},
//         {3.7974},
//         {3.7872},
//         {3.7782},
//         {3.7688},
//         {3.7605},
//         {3.7522},
//         {3.7436},
//         {3.7366},
//         {3.7289},
//         {3.7219},
//         {3.7151},
//         {3.7088},
//         {3.7019},
//         {3.6961},
//         {3.6902},
//         {3.6846},
//         {3.6791},
//         {3.6736},
//         {3.6689},
//         {3.6633},
//         {3.6592},
//         {3.6541},
//         {3.6496},
//         {3.6455},
//         {3.6413},
//         {3.637},
//         {3.633},
//         {3.6293},
//         {3.6254},
//         {3.6218},
//         {3.6184},
//         {3.6148},
//         {3.6114},
//         {3.6081},
//         {3.605},
//         {3.602},
//         {3.5987},
//         {3.596},
//         {3.593},
//         {3.5902},
//         {3.5873},
//         {3.5849},
//         {3.5821},
//         {3.5795},
//         {3.5772},
//         {3.5745},
//         {3.5723},
//         {3.5697},
//         {3.5676},
//         {3.5652},
//         {3.5632},
//         {3.5608},
//         {3.5587},
//         {3.5566},
//         {3.5545},
//         {3.5526},
//         {3.5504},
//         {3.5487},
//         {3.5466},
//         {3.5448},
//         {3.5428},
//         {3.5411},
//         {3.5393},
//         {3.5374},
//         {3.5357},
//         {3.5339},
//         {3.5323},
//         {3.5305},
//         {3.5288},
//         {3.5273},
//         {3.5255},
//         {3.524},
//         {3.5224},
//         {3.5208},
//         {3.5192},
//         {3.5177},
//         {3.5161},
//         {3.5146},
//         {3.5131},
//         {3.5116},
//         {3.5101},
//         {3.5086},
//         {3.5072},
//         {3.5057},
//         {3.5043},
//         {3.5029},
//         {3.5014},
//         {3.5},
//         {3.4986},
//         {3.4972},
//         {3.4958},
//         {3.4944},
//         {3.493},
//         {3.4916},
//         {3.4902},
//         {3.4888},
//         {3.4875},
//         {3.4861},
//         {3.4847},
//         {3.4834},
//         {3.4819},
//         {3.4806},
//         {3.4793},
//         {3.4778},
//         {3.4765},
//         {3.4751},
//         {3.4737},
//         {3.4723},
//         {3.471},
//         {3.4696},
//         {3.4682},
//         {3.4668},
//         {3.4654},
//         {3.4639},
//         {3.4625},
//         {3.4611},
//         {3.4597},
//         {3.4583},
//         {3.4567},
//         {3.4554},
//         {3.4539},
//         {3.4523},
//         {3.451},
//         {3.4495},
//         {3.4478},
//         {3.4464},
//         {3.445},
//         {3.4433},
//         {3.4418},
//         {3.4402},
//         {3.4386},
//         {3.4371},
//         {3.4354},
//         {3.4337},
//         {3.4322},
//         {3.4303},
//         {3.4288},
//         {3.4271},
//         {3.4251},
//         {3.4236},
//         {3.4219},
//         {3.4198},
//         {3.4182},
//         {3.4164},
//         {3.4143},
//         {3.4128},
//         {3.4104},
//         {3.4088},
//         {3.4068},
//         {3.4046},
//         {3.4026},
//         {3.4006},
//         {3.3984},
//         {3.3964},
//         {3.3941},
//         {3.392},
//         {3.3898},
//         {3.3871},
//         {3.3853},
//         {3.3826},
//         {3.3804},
//         {3.3777},
//         {3.3754},
//         {3.3721},
//         {3.337},
//         {3.2862},
//         {3.2357},
//         {3.1847},
//         {3.1346},
//         {3.0839},
//         {3.0335},
//         {2.9829},
//         {2.9332},
//         {2.8828},
//         {2.8326},
//         {2.7826},
//         {2.7326},
//         {2.6825},
//         {2.6332},
//         {2.5829},
//         {2.5338},
//         {2.4836},
//         {2.4344},
//         {2.385},
//         {2.3354},
//         {2.2868},
//         {2.237},
//         {2.1881},
//         {2.1389},
//         {2.0903},
//         {2.0415},
//         {1.9925},
//         {1.9442},
//         {1.8956},
//         {1.8468},
//         {1.7987},
//         {1.75},
//         {1.7021},
//         {1.6536},
//         {1.6057},
//         {1.5582},
//         {1.5102},
//         {1.4617},
//         {1.415},
//         {1.3663},
//         {1.3195},
//         {1.2717},
//         {1.2243},
//         {1.1774},
//         {1.1295},
//         {1.0834},
//         {1.0351},
//         {0.9886},
//         {0.942},
//         {0.8946},
//         {0.8476},
//         {0.8018},
//         {0.7549},
//         {0.7073},
//         {0.6612},
//         {0.6149},
//         {0.5687},
//         {0.5215},
//         {0.4759},
//         {0.4287},
//         {0.382},
//         {0.3365},
//         {0.2896},
//         {0.2443},
//         {0.1969},
//         {0.1505},
//         {0.1051},
//         {0.0542}
//     }
// ;
//     std::vector<std::vector<double>> AWP:: loopbackRight = {
//         {0},
//         {0.0253},
//         {0.0633},
//         {0.1004},
//         {0.1383},
//         {0.175},
//         {0.212},
//         {0.2497},
//         {0.2863},
//         {0.3226},
//         {0.3598},
//         {0.3956},
//         {0.4319},
//         {0.4671},
//         {0.5027},
//         {0.5375},
//         {0.5723},
//         {0.6052},
//         {0.6398},
//         {0.6716},
//         {0.7046},
//         {0.7355},
//         {0.7665},
//         {0.7967},
//         {0.825},
//         {0.8538},
//         {0.8802},
//         {0.9063},
//         {0.9311},
//         {0.9541},
//         {0.9756},
//         {0.9965},
//         {1.0147},
//         {1.0315},
//         {1.0457},
//         {1.0588},
//         {1.0684},
//         {1.076},
//         {1.0807},
//         {1.0823},
//         {1.0807},
//         {1.0761},
//         {1.0665},
//         {1.0541},
//         {1.0373},
//         {1.0146},
//         {0.9884},
//         {0.9269},
//         {0.8407},
//         {0.7722},
//         {0.7071},
//         {0.6433},
//         {0.5838},
//         {0.5272},
//         {0.4721},
//         {0.4225},
//         {0.373},
//         {0.33},
//         {0.2897},
//         {0.2513},
//         {0.2182},
//         {0.1881},
//         {0.1634},
//         {0.1394},
//         {0.1234},
//         {0.1082},
//         {0.0987},
//         {0.0932},
//         {0.0909},
//         {0.0926},
//         {0.1},
//         {0.1098},
//         {0.1246},
//         {0.1428},
//         {0.1659},
//         {0.1939},
//         {0.2236},
//         {0.259},
//         {0.2997},
//         {0.3407},
//         {0.3892},
//         {0.44},
//         {0.4939},
//         {0.5528},
//         {0.6148},
//         {0.6804},
//         {0.7503},
//         {0.8233},
//         {0.9012},
//         {0.9807},
//         {1.0627},
//         {1.1469},
//         {1.2334},
//         {1.3216},
//         {1.4109},
//         {1.5015},
//         {1.5937},
//         {1.6877},
//         {1.7816},
//         {1.8778},
//         {1.9743},
//         {2.0211},
//         {2.0419},
//         {2.0643},
//         {2.0836},
//         {2.0999},
//         {2.1143},
//         {2.1263},
//         {2.1379},
//         {2.1484},
//         {2.1595},
//         {2.1073},
//         {1.2134},
//         {0.9437},
//         {0.8882},
//         {0.8337},
//         {0.7818},
//         {0.7328},
//         {0.6867},
//         {0.6435},
//         {0.6034},
//         {0.5684},
//         {0.5345},
//         {0.5019},
//         {0.4766},
//         {0.4526},
//         {0.432},
//         {0.4148},
//         {0.4012},
//         {0.3931},
//         {0.3866},
//         {0.3815},
//         {0.3841},
//         {0.3882},
//         {0.396},
//         {0.4072},
//         {0.4241},
//         {0.4404},
//         {0.4643},
//         {0.4896},
//         {0.5183},
//         {0.5504},
//         {0.5858},
//         {0.6244},
//         {0.668},
//         {0.713},
//         {0.761},
//         {0.8103},
//         {0.8677},
//         {0.9229},
//         {0.9826},
//         {1.0466},
//         {1.1118},
//         {1.1781},
//         {1.2515},
//         {1.3217},
//         {1.3992},
//         {1.4724},
//         {1.5492},
//         {1.6279},
//         {1.7047},
//         {1.7831},
//         {1.8606},
//         {1.9403},
//         {2.0189},
//         {2.0953},
//         {2.1755},
//         {2.2513},
//         {2.3306},
//         {2.4057},
//         {2.4829},
//         {2.5578},
//         {2.6338},
//         {2.7075},
//         {2.7674},
//         {2.7966},
//         {2.8277},
//         {2.8583},
//         {2.8851},
//         {2.9105},
//         {2.9368},
//         {2.9587},
//         {2.9806},
//         {3.0018},
//         {3.0213},
//         {3.0404},
//         {3.0569},
//         {3.0745},
//         {3.0898},
//         {3.1053},
//         {3.1192},
//         {3.1332},
//         {3.1462},
//         {3.1585},
//         {3.1703},
//         {3.1815},
//         {3.1923},
//         {3.2026},
//         {3.2128},
//         {3.2218},
//         {3.2312},
//         {3.2395},
//         {3.2478},
//         {3.2564},
//         {3.2634},
//         {3.2711},
//         {3.2781},
//         {3.2849},
//         {3.2912},
//         {3.2981},
//         {3.3039},
//         {3.3098},
//         {3.3154},
//         {3.3209},
//         {3.3264},
//         {3.3311},
//         {3.3367},
//         {3.3408},
//         {3.3459},
//         {3.3504},
//         {3.3545},
//         {3.3587},
//         {3.363},
//         {3.367},
//         {3.3707},
//         {3.3746},
//         {3.3782},
//         {3.3816},
//         {3.3852},
//         {3.3886},
//         {3.3919},
//         {3.395},
//         {3.398},
//         {3.4013},
//         {3.404},
//         {3.407},
//         {3.4098},
//         {3.4127},
//         {3.4151},
//         {3.4179},
//         {3.4205},
//         {3.4228},
//         {3.4255},
//         {3.4277},
//         {3.4303},
//         {3.4324},
//         {3.4348},
//         {3.4368},
//         {3.4392},
//         {3.4413},
//         {3.4434},
//         {3.4455},
//         {3.4474},
//         {3.4496},
//         {3.4513},
//         {3.4534},
//         {3.4552},
//         {3.4572},
//         {3.4589},
//         {3.4607},
//         {3.4626},
//         {3.4643},
//         {3.4661},
//         {3.4677},
//         {3.4695},
//         {3.4712},
//         {3.4727},
//         {3.4745},
//         {3.476},
//         {3.4776},
//         {3.4792},
//         {3.4808},
//         {3.4823},
//         {3.4839},
//         {3.4854},
//         {3.4869},
//         {3.4884},
//         {3.4899},
//         {3.4914},
//         {3.4928},
//         {3.4943},
//         {3.4957},
//         {3.4971},
//         {3.4986},
//         {3.5},
//         {3.5014},
//         {3.5028},
//         {3.5042},
//         {3.5056},
//         {3.507},
//         {3.5084},
//         {3.5098},
//         {3.5112},
//         {3.5125},
//         {3.5139},
//         {3.5153},
//         {3.5166},
//         {3.5181},
//         {3.5194},
//         {3.5207},
//         {3.5222},
//         {3.5235},
//         {3.5249},
//         {3.5263},
//         {3.5277},
//         {3.529},
//         {3.5304},
//         {3.5318},
//         {3.5332},
//         {3.5346},
//         {3.5361},
//         {3.5375},
//         {3.5389},
//         {3.5403},
//         {3.5417},
//         {3.5433},
//         {3.5446},
//         {3.5461},
//         {3.5477},
//         {3.549},
//         {3.5505},
//         {3.5522},
//         {3.5536},
//         {3.555},
//         {3.5567},
//         {3.5582},
//         {3.5598},
//         {3.5614},
//         {3.5629},
//         {3.5646},
//         {3.5663},
//         {3.5678},
//         {3.5697},
//         {3.5712},
//         {3.5729},
//         {3.5749},
//         {3.5764},
//         {3.5781},
//         {3.5802},
//         {3.5817},
//         {3.5836},
//         {3.5857},
//         {3.5872},
//         {3.5896},
//         {3.5912},
//         {3.5932},
//         {3.5954},
//         {3.5974},
//         {3.5994},
//         {3.6016},
//         {3.6036},
//         {3.6059},
//         {3.608},
//         {3.6102},
//         {3.6129},
//         {3.6147},
//         {3.6174},
//         {3.6196},
//         {3.6223},
//         {3.6246},
//         {3.6264},
//         {3.5957},
//         {3.5467},
//         {3.4971},
//         {3.4482},
//         {3.3983},
//         {3.3489},
//         {3.2993},
//         {3.2499},
//         {3.1997},
//         {3.1501},
//         {3.1002},
//         {3.0502},
//         {3.0001},
//         {2.9503},
//         {2.8997},
//         {2.8499},
//         {2.799},
//         {2.7491},
//         {2.6983},
//         {2.6477},
//         {2.5974},
//         {2.5461},
//         {2.4957},
//         {2.4445},
//         {2.3938},
//         {2.3425},
//         {2.2913},
//         {2.2404},
//         {2.1888},
//         {2.1373},
//         {2.086},
//         {2.034},
//         {1.9826},
//         {1.9305},
//         {1.8789},
//         {1.827},
//         {1.7747},
//         {1.7225},
//         {1.671},
//         {1.6176},
//         {1.5662},
//         {1.513},
//         {1.4608},
//         {1.4082},
//         {1.3551},
//         {1.3032},
//         {1.2492},
//         {1.1971},
//         {1.1439},
//         {1.0905},
//         {1.0375},
//         {0.9849},
//         {0.9312},
//         {0.8775},
//         {0.8247},
//         {0.7711},
//         {0.7178},
//         {0.6638},
//         {0.611},
//         {0.5566},
//         {0.5028},
//         {0.4496},
//         {0.3951},
//         {0.3424},
//         {0.2879},
//         {0.2335},
//         {0.1805},
//         {0.1257},
//         {0.0668}
//     }
// ;

std::vector<std::vector<double>> AWP::path1NewLeft = {
        {0},
        {0.0273},
        {0.067},
        {0.1078},
        {0.149},
        {0.19},
        {0.2309},
        {0.2721},
        {0.3127},
        {0.3538},
        {0.3946},
        {0.435},
        {0.4763},
        {0.5162},
        {0.5569},
        {0.5971},
        {0.6372},
        {0.6771},
        {0.7167},
        {0.757},
        {0.7953},
        {0.8351},
        {0.874},
        {0.9131},
        {0.9508},
        {0.9892},
        {1.0274},
        {1.0649},
        {1.1017},
        {1.1393},
        {1.175},
        {1.2122},
        {1.247},
        {1.2826},
        {1.3173},
        {1.3515},
        {1.386},
        {1.4184},
        {1.4517},
        {1.4837},
        {1.5146},
        {1.5461},
        {1.576},
        {1.6052},
        {1.6336},
        {1.662},
        {1.6882},
        {1.714},
        {1.7397},
        {1.7636},
        {1.7864},
        {1.8081},
        {1.8296},
        {1.849},
        {1.8672},
        {1.8851},
        {1.8998},
        {1.9156},
        {1.9287},
        {1.9409},
        {1.9491},
        {1.9137},
        {1.8652},
        {1.8237},
        {1.7827},
        {1.7436},
        {1.7066},
        {1.6704},
        {1.6358},
        {1.6027},
        {1.5712},
        {1.5417},
        {1.5127},
        {1.4864},
        {1.4606},
        {1.438},
        {1.4148},
        {1.3955},
        {1.3766},
        {1.3588},
        {1.3438},
        {1.3299},
        {1.3175},
        {1.3069},
        {1.2984},
        {1.2909},
        {1.2851},
        {1.2803},
        {1.2788},
        {1.2777},
        {1.2777},
        {1.2803},
        {1.2838},
        {1.2888},
        {1.2953},
        {1.3044},
        {1.312},
        {1.3244},
        {1.3359},
        {1.3497},
        {1.3637},
        {1.3778},
        {1.3619},
        {1.3412},
        {1.3246},
        {1.3092},
        {1.2909},
        {1.2752},
        {1.256},
        {1.2383},
        {1.2199},
        {1.1996},
        {1.18},
        {1.1594},
        {1.1382},
        {1.1164},
        {1.0935},
        {1.0709},
        {1.0468},
        {1.0231},
        {0.9983},
        {0.9726},
        {0.9473},
        {0.921},
        {0.8938},
        {0.8671},
        {0.8395},
        {0.811},
        {0.783},
        {0.7538},
        {0.7251},
        {0.6957},
        {0.6655},
        {0.6359},
        {0.6052},
        {0.5755},
        {0.5435},
        {0.5137},
        {0.4817},
        {0.4504},
        {0.4196},
        {0.3867},
        {0.3561},
        {0.3233},
        {0.2916},
        {0.259},
        {0.2268},
        {0.1953},
        {0.162},
        {0.1295},
        {0.0974},
        {0.0648},
        {0.0315}
    }
;
std::vector<std::vector<double>> AWP::path1NewRight = {
        {0},
        {0.0334},
        {0.0865},
        {0.1428},
        {0.2019},
        {0.2614},
        {0.32},
        {0.3785},
        {0.4377},
        {0.4964},
        {0.5556},
        {0.6152},
        {0.674},
        {0.7344},
        {0.7936},
        {0.8534},
        {0.9133},
        {0.9733},
        {1.0334},
        {1.0932},
        {1.155},
        {1.215},
        {1.276},
        {1.3371},
        {1.3995},
        {1.461},
        {1.5227},
        {1.5853},
        {1.6484},
        {1.7109},
        {1.7752},
        {1.838},
        {1.9032},
        {1.9676},
        {2.0329},
        {2.0986},
        {2.1641},
        {2.2317},
        {2.2983},
        {2.3664},
        {2.4355},
        {2.504},
        {2.574},
        {2.6449},
        {2.7165},
        {2.7881},
        {2.8619},
        {2.9361},
        {3.0103},
        {3.0865},
        {3.1637},
        {3.242},
        {3.3204},
        {3.401},
        {3.4828},
        {3.5649},
        {3.6502},
        {3.7343},
        {3.8213},
        {3.9092},
        {3.9976},
        {4.0204},
        {4.0054},
        {3.9859},
        {3.9684},
        {3.9513},
        {3.9347},
        {3.9196},
        {3.9053},
        {3.892},
        {3.8795},
        {3.8673},
        {3.857},
        {3.8464},
        {3.8378},
        {3.8281},
        {3.8215},
        {3.8133},
        {3.8069},
        {3.8018},
        {3.7961},
        {3.7917},
        {3.7879},
        {3.7847},
        {3.7815},
        {3.7794},
        {3.7779},
        {3.7776},
        {3.776},
        {3.7762},
        {3.7774},
        {3.778},
        {3.7797},
        {3.7818},
        {3.7845},
        {3.7866},
        {3.7919},
        {3.7944},
        {3.7996},
        {3.8041},
        {3.8103},
        {3.8138},
        {3.7637},
        {3.6843},
        {3.601},
        {3.5163},
        {3.4346},
        {3.3503},
        {3.2695},
        {3.1873},
        {3.1056},
        {3.026},
        {2.9456},
        {2.8662},
        {2.7874},
        {2.7092},
        {2.6321},
        {2.5547},
        {2.4788},
        {2.4025},
        {2.3272},
        {2.253},
        {2.1783},
        {2.1046},
        {2.0317},
        {1.9585},
        {1.8861},
        {1.8145},
        {1.7425},
        {1.6717},
        {1.6004},
        {1.5298},
        {1.46},
        {1.3896},
        {1.3204},
        {1.25},
        {1.182},
        {1.1118},
        {1.0437},
        {0.9752},
        {0.9058},
        {0.8388},
        {0.7694},
        {0.7021},
        {0.6336},
        {0.5661},
        {0.4986},
        {0.4301},
        {0.363},
        {0.2956},
        {0.2278},
        {0.1599},
        {0.0921}
    }
;

std::vector<std::vector<double>> AWP::testLeft = {
        {0},
        {-0.031},
        {-0.0762},
        {-0.1262},
        {-0.176},
        {-0.2254},
        {-0.2753},
        {-0.3252},
        {-0.3754},
        {-0.4256},
        {-0.4753},
        {-0.5252},
        {-0.5753},
        {-0.6252},
        {-0.6752},
        {-0.7252},
        {-0.7751},
        {-0.8252},
        {-0.8751},
        {-0.9252},
        {-0.9751},
        {-1.0251},
        {-1.0752},
        {-1.1251},
        {-1.1751},
        {-1.2251},
        {-1.2751},
        {-1.3252},
        {-1.3751},
        {-1.4251},
        {-1.4752},
        {-1.5252},
        {-1.5751},
        {-1.6251},
        {-1.6751},
        {-1.7251},
        {-1.7751},
        {-1.8251},
        {-1.8751},
        {-1.925},
        {-1.9751},
        {-2.025},
        {-2.075},
        {-2.125},
        {-2.1751},
        {-2.2251},
        {-2.2751},
        {-2.3251},
        {-2.3751},
        {-2.4251},
        {-2.4751},
        {-2.5251},
        {-2.5751},
        {-2.6251},
        {-2.6751},
        {-2.7251},
        {-2.7751},
        {-2.825},
        {-2.875},
        {-2.925},
        {-2.975},
        {-3.025},
        {-3.075},
        {-3.125},
        {-3.1751},
        {-3.2251},
        {-3.2751},
        {-3.3251},
        {-3.3751},
        {-3.425},
        {-3.475},
        {-3.525},
        {-3.5751},
        {-3.6251},
        {-3.675},
        {-3.725},
        {-3.7751},
        {-3.8251},
        {-3.8751},
        {-3.9251},
        {-3.9751},
        {-4.0251},
        {-4.0751},
        {-4.125},
        {-4.175},
        {-4.2251},
        {-4.2751},
        {-4.325},
        {-4.3751},
        {-4.4251},
        {-4.4751},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.4847},
        {-4.4359},
        {-4.3858},
        {-4.3358},
        {-4.2858},
        {-4.2358},
        {-4.1858},
        {-4.1358},
        {-4.0858},
        {-4.0358},
        {-3.9858},
        {-3.9358},
        {-3.8858},
        {-3.8358},
        {-3.7858},
        {-3.7358},
        {-3.6858},
        {-3.6359},
        {-3.5859},
        {-3.5358},
        {-3.4858},
        {-3.4358},
        {-3.3858},
        {-3.3358},
        {-3.2858},
        {-3.2358},
        {-3.1858},
        {-3.1359},
        {-3.0858},
        {-3.0358},
        {-2.9859},
        {-2.9359},
        {-2.8859},
        {-2.8358},
        {-2.7858},
        {-2.7359},
        {-2.6859},
        {-2.6359},
        {-2.5859},
        {-2.5358},
        {-2.4858},
        {-2.4358},
        {-2.3859},
        {-2.3359},
        {-2.2858},
        {-2.2359},
        {-2.1859},
        {-2.1359},
        {-2.0858},
        {-2.0358},
        {-1.9859},
        {-1.9359},
        {-1.8859},
        {-1.8359},
        {-1.7859},
        {-1.736},
        {-1.6859},
        {-1.6359},
        {-1.5859},
        {-1.5359},
        {-1.4859},
        {-1.4359},
        {-1.3858},
        {-1.3358},
        {-1.2858},
        {-1.2359},
        {-1.1859},
        {-1.1359},
        {-1.0859},
        {-1.0359},
        {-0.9859},
        {-0.9359},
        {-0.8859},
        {-0.8359},
        {-0.786},
        {-0.7359},
        {-0.6859},
        {-0.636},
        {-0.5859},
        {-0.5358},
        {-0.4859},
        {-0.436},
        {-0.3858},
        {-0.3358},
        {-0.2858},
        {-0.2358},
        {-0.1857},
        {-0.1357},
        {-0.0859},
        {-0.0305}
    }
;
std::vector<std::vector<double>> AWP::testRight = {
        {0},
        {-0.031},
        {-0.0762},
        {-0.1262},
        {-0.176},
        {-0.2254},
        {-0.2753},
        {-0.3252},
        {-0.3754},
        {-0.4256},
        {-0.4753},
        {-0.5252},
        {-0.5753},
        {-0.6252},
        {-0.6752},
        {-0.7252},
        {-0.7751},
        {-0.8252},
        {-0.8751},
        {-0.9252},
        {-0.9751},
        {-1.0251},
        {-1.0752},
        {-1.1251},
        {-1.1751},
        {-1.2251},
        {-1.2751},
        {-1.3252},
        {-1.3751},
        {-1.4251},
        {-1.4752},
        {-1.5252},
        {-1.5751},
        {-1.6251},
        {-1.6751},
        {-1.7251},
        {-1.7751},
        {-1.8251},
        {-1.8751},
        {-1.925},
        {-1.9751},
        {-2.025},
        {-2.075},
        {-2.125},
        {-2.1751},
        {-2.2251},
        {-2.2751},
        {-2.3251},
        {-2.3751},
        {-2.4251},
        {-2.4751},
        {-2.5251},
        {-2.5751},
        {-2.6251},
        {-2.6751},
        {-2.7251},
        {-2.7751},
        {-2.825},
        {-2.875},
        {-2.925},
        {-2.975},
        {-3.025},
        {-3.075},
        {-3.125},
        {-3.1751},
        {-3.2251},
        {-3.2751},
        {-3.3251},
        {-3.3751},
        {-3.425},
        {-3.475},
        {-3.525},
        {-3.5751},
        {-3.6251},
        {-3.675},
        {-3.725},
        {-3.7751},
        {-3.8251},
        {-3.8751},
        {-3.9251},
        {-3.9751},
        {-4.0251},
        {-4.0751},
        {-4.125},
        {-4.175},
        {-4.2251},
        {-4.2751},
        {-4.325},
        {-4.3751},
        {-4.4251},
        {-4.4751},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.5},
        {-4.4847},
        {-4.4359},
        {-4.3858},
        {-4.3358},
        {-4.2858},
        {-4.2358},
        {-4.1858},
        {-4.1358},
        {-4.0858},
        {-4.0358},
        {-3.9858},
        {-3.9358},
        {-3.8858},
        {-3.8358},
        {-3.7858},
        {-3.7358},
        {-3.6858},
        {-3.6359},
        {-3.5859},
        {-3.5358},
        {-3.4858},
        {-3.4358},
        {-3.3858},
        {-3.3358},
        {-3.2858},
        {-3.2358},
        {-3.1858},
        {-3.1359},
        {-3.0858},
        {-3.0358},
        {-2.9859},
        {-2.9359},
        {-2.8859},
        {-2.8358},
        {-2.7858},
        {-2.7359},
        {-2.6859},
        {-2.6359},
        {-2.5859},
        {-2.5358},
        {-2.4858},
        {-2.4358},
        {-2.3859},
        {-2.3359},
        {-2.2858},
        {-2.2359},
        {-2.1859},
        {-2.1359},
        {-2.0858},
        {-2.0358},
        {-1.9859},
        {-1.9359},
        {-1.8859},
        {-1.8359},
        {-1.7859},
        {-1.736},
        {-1.6859},
        {-1.6359},
        {-1.5859},
        {-1.5359},
        {-1.4859},
        {-1.4359},
        {-1.3858},
        {-1.3358},
        {-1.2858},
        {-1.2359},
        {-1.1859},
        {-1.1359},
        {-1.0859},
        {-1.0359},
        {-0.9859},
        {-0.9359},
        {-0.8859},
        {-0.8359},
        {-0.786},
        {-0.7359},
        {-0.6859},
        {-0.636},
        {-0.5859},
        {-0.5358},
        {-0.4859},
        {-0.436},
        {-0.3858},
        {-0.3358},
        {-0.2858},
        {-0.2358},
        {-0.1857},
        {-0.1357},
        {-0.0859},
        {-0.0305}
    }
;
















