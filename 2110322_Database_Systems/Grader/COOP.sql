--
-- PostgreSQL database dump
--

\restrict Cu3GFcueDe1UeZfVBLkeMHWgZoHF0txVYIGFCFFd2vRZ9KY4g5xA2L9ddOqtKMt

-- Dumped from database version 18.1 (Debian 18.1-1.pgdg13+2)
-- Dumped by pg_dump version 18.1 (Debian 18.1-1.pgdg13+2)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET transaction_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
--

CREATE TABLE public.customer (
    cid integer NOT NULL,
    cname text NOT NULL
);



--
--

CREATE SEQUENCE public.customer_cid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;



--
--

ALTER SEQUENCE public.customer_cid_seq OWNED BY public.customer.cid;


--
--

CREATE TABLE public.placement (
    pid integer DEFAULT 0 NOT NULL,
    oid integer DEFAULT 0 NOT NULL,
    cid integer DEFAULT 0 NOT NULL
);



--
--

CREATE TABLE public.porder (
    oid integer NOT NULL
);


--
--
--

CREATE SEQUENCE public.porder_oid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


--
--

ALTER SEQUENCE public.porder_oid_seq OWNED BY public.porder.oid;


--
--

CREATE TABLE public.product (
    pid integer NOT NULL,
    pprice real DEFAULT 0.0 NOT NULL,
    pcategory character varying(50) NOT NULL,
    pname character varying(50) NOT NULL
);

--
--

CREATE SEQUENCE public.product_pid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;



--
--

ALTER SEQUENCE public.product_pid_seq OWNED BY public.product.pid;


--
--

ALTER TABLE ONLY public.customer ALTER COLUMN cid SET DEFAULT nextval('public.customer_cid_seq'::regclass);


--
--

ALTER TABLE ONLY public.porder ALTER COLUMN oid SET DEFAULT nextval('public.porder_oid_seq'::regclass);


--
--

ALTER TABLE ONLY public.product ALTER COLUMN pid SET DEFAULT nextval('public.product_pid_seq'::regclass);


--
--

COPY public.customer (cid, cname) FROM stdin;
1	Somchai Jaidee
2	Nattaporn Srisuk
3	Arthit Wongwat
4	Siriporn Boonmee
5	Teerapat Saeli
6	Kittisak Charoen
7	Waraporn Kaewmanee
8	Ananda Sukhum
9	Pimchanok Wattana
10	Woraphon Thongdee
11	Chutima Ratanaporn
12	Thanawat Chaiyaphum
13	Supaporn Kiat
14	Narong Petch
15	Kanya Prasert
16	Somsak Siripong
17	Ratchanok Intanon
18	Phuwanat Kunlanat
19	Jiraporn Saelim
20	Wichai Raksa
21	Kevin Miller
22	Li Wei
23	Sakura Tanaka
24	Michael Smith
25	Aung Kyaw Min
26	Pongsakorn Meesuk
27	Malee Sawat
28	Suwanna Kong
29	Chaiwat Panich
30	Orathai Srivilai
31	Prasit Chok
32	Ratana Pol
33	Sudarat Kaew
34	Wipa Niyom
35	Surachai Yindee
36	Nongnuch Hom
37	Apisit Vejjajiva
38	Thongchai McIntyre
39	Patcharin Juntra
40	Suriya Jung
41	Emma Johansson
42	Zhang Hao
43	Hiroshi Sato
44	Sarah O`Connor
45	Nguyen Van Minh
46	Kamonwan Bua
47	Preeda Suk
48	Manop Jit
49	Sunisa Lee
50	Tanapong Plearn
51	Wilai Porn
52	Sombat Metta
53	Chana Song
54	Areeya Chumsai
55	Bundit Ung
56	Chakrit Yam
57	Darunee Suwan
58	Ekkachai Udom
59	Fahsai Paweensuda
60	Gamon Tip
61	Hans Mueller
62	Chen Xiu Ying
63	Kenji Nakamura
64	Jessica Brown
65	Siti Nurhaliza
66	Hatairat Ping
67	Issara Keng
68	Jaran Man
69	Kanchana Wung
70	Lamduan Sai
71	Mana Jai
72	Nipa Rat
73	Opas Liang
74	Parichat Dao
75	Rewat Put
76	Sasithorn Jan
77	Tawatchai Muk
78	Ubol Ratana
79	Vanida Tiam
80	Wanchai Poom
81	David Wilson
82	Kim Min-jun
83	Yuki Suzuki
84	Robert Taylor
85	Sofia Rossi
86	Yupa Sorn
87	Zanya Thep
88	Anusorn Phat
89	Boonchuay Ruang
90	Chatchai Pleng
91	Duangjai Rak
92	Eak Ua
93	Kamol Pop
94	Ladda Wan
95	Mongkol Chok
96	Naraorn Pat
97	Pierre Dubois
98	Wang Fang
99	Ali Ahmed
100	Chloe Martin
\.


--
--

COPY public.placement (pid, oid, cid) FROM stdin;
18	1	1
79	1	1
16	2	2
50	2	2
115	2	2
103	2	2
113	3	3
112	4	4
1	4	4
20	4	4
177	5	5
38	5	5
77	6	6
29	7	7
114	8	8
82	8	8
47	8	8
178	9	9
115	9	9
178	10	10
177	10	10
98	10	10
29	10	10
80	11	11
47	11	11
3	12	12
20	12	12
112	13	13
3	13	13
85	13	13
46	14	14
39	14	14
113	15	15
21	15	15
38	15	15
79	15	15
98	16	16
20	16	16
176	17	17
17	17	17
19	17	17
51	18	18
29	18	18
9	19	19
44	19	19
1	19	19
84	19	19
83	20	20
20	20	20
31	20	20
80	21	21
178	21	21
99	21	21
46	22	22
95	22	22
30	22	22
111	22	22
81	23	23
19	23	23
46	23	23
31	23	23
1	24	24
115	25	25
3	25	25
112	25	25
81	26	26
178	26	26
115	26	26
9	27	27
99	27	27
84	28	28
104	29	29
83	29	29
19	29	29
16	30	30
177	30	30
95	30	30
98	31	31
84	31	31
78	31	31
44	32	32
85	32	32
103	32	32
38	33	33
1	33	33
114	33	33
30	33	33
18	34	34
85	34	34
78	34	34
176	35	35
114	35	35
84	35	35
46	36	36
99	37	37
2	38	38
82	38	38
79	38	38
104	39	39
98	39	39
15	39	39
47	39	39
19	40	40
31	40	40
103	40	40
3	41	41
10	41	41
99	41	41
112	42	42
49	42	42
44	42	42
81	42	42
48	43	43
2	43	43
115	43	43
82	43	43
114	44	44
19	44	44
78	44	44
81	45	45
29	45	45
31	45	45
96	46	46
113	47	47
30	47	47
104	48	48
96	49	49
83	49	49
38	49	49
104	50	50
82	50	50
78	50	50
95	50	50
31	51	51
46	52	52
178	52	52
102	52	52
10	53	53
99	53	53
96	54	54
30	54	54
20	55	55
78	55	55
50	56	56
39	57	57
85	58	58
38	58	58
103	58	58
9	59	59
44	60	60
78	61	61
9	62	62
2	62	62
3	62	62
30	63	63
3	64	64
50	65	65
20	65	65
77	65	65
114	66	66
47	67	67
9	68	68
15	68	68
113	69	69
177	69	69
96	70	70
51	70	70
77	70	70
46	70	70
10	71	71
2	72	72
29	72	72
95	72	72
111	72	72
38	73	73
47	73	73
30	73	73
39	73	73
177	74	74
78	74	74
47	74	74
9	75	75
84	75	75
111	76	76
176	77	77
30	77	77
103	77	77
176	78	78
48	78	78
47	79	79
17	80	80
48	81	81
81	81	81
10	81	81
16	82	82
10	82	82
84	82	82
46	82	82
47	83	83
102	83	83
31	83	83
20	84	84
21	85	85
98	86	86
103	86	86
51	87	87
29	87	87
82	88	88
78	88	88
30	88	88
49	89	89
178	89	89
99	90	90
77	90	90
111	91	91
79	91	91
15	91	91
3	92	92
20	92	92
51	93	93
44	93	93
46	93	93
48	94	94
113	94	94
46	94	94
112	95	95
3	95	95
18	95	95
51	95	95
16	96	96
1	97	97
51	97	97
20	98	98
46	98	98
17	99	99
114	99	99
77	99	99
104	100	100
21	100	100
56	85	85
90	85	85
\.


--
--

COPY public.porder (oid) FROM stdin;
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
\.


--
--

COPY public.product (pid, pprice, pcategory, pname) FROM stdin;
1	7	beverage	Crystal Drinking Water 600ml
2	7	beverage	Singha Drinking Water 600ml
3	10	beverage	Nestle Pure Life 1.5L
4	15	beverage	Coke Original 325ml
5	15	beverage	Pepsi Original 325ml
6	15	beverage	Sprite 325ml
7	15	beverage	Fanta Orange 325ml
8	15	beverage	Schweppes Lime Soda
9	12	beverage	Oishi Green Tea Original 380ml
10	12	beverage	Oishi Green Tea Honey Lemon 380ml
11	16	beverage	Ichitan Green Tea Honey Lemon
12	16	beverage	Ichitan Yen Yen Herbal Tea
13	20	beverage	Oishi Chakulza
14	25	beverage	Fuji Green Tea Natural
15	10	beverage	Lactasoy Soymilk Original 300ml
16	10	beverage	Lactasoy Chocolate 300ml
17	12	beverage	Vitamilk Original Bottle
18	13	beverage	Dutch Mill Yogurt Drink Strawberry
19	13	beverage	Dutch Mill Yogurt Drink Orange
20	12	beverage	Foremost Milk Plain 225ml
21	12	beverage	Foremost Milk Chocolate 225ml
22	15	beverage	Meiji Pasteurized Milk 200ml
23	15	beverage	Meiji Coffee Milk 200ml
24	15	beverage	Birdy Robusta Canned Coffee
25	15	beverage	Birdy Espresso Canned Coffee
26	15	beverage	Nescafe Espresso Roast Can
27	15	beverage	Nescafe Black Ice Can
28	30	beverage	Starbucks Frappuccino Bottle
29	10	beverage	M-150 Energy Drink
30	10	beverage	Carabao Dang Energy Drink
31	12	beverage	Sponsor Electrolyte Original
32	15	beverage	C-Vitt Lemon 140ml
33	15	beverage	C-Vitt Orange 140ml
34	20	beverage	Mansome Vitamin Water
35	18	beverage	Malee 100% Orange Juice
36	18	beverage	Tipco 100% Apple Juice
37	25	beverage	Doi Kham Tomato Juice
38	10	beverage	Jele Beautie Collagen
39	12	beverage	Nata De Coco Lychee
40	15	beverage	Ovaltine Malt Box
41	15	beverage	Milo Active-Go Box
42	35	beverage	Almond Breeze Original
43	20	beverage	Gatorade Blue Bolt
44	12	beverage	Grass Jelly Drink
45	15	beverage	Singha Lemon Soda Can
46	7	snack	MAMA Tom Yum Kung Instant Noodles
47	7	snack	MAMA Minced Pork Instant Noodles
48	7	snack	MAMA Creamy Tom Yum Noodles
49	7	snack	Wai Wai Instant Noodles Original
50	7	snack	Yum Yum Jumbo Minced Pork
51	8	snack	Nissin Instant Noodles Spicy
52	15	snack	MAMA Cup Moo Sub
53	15	snack	MAMA Cup Tom Yum Kung
54	15	snack	MAMA Cup Pa-Lo Duck
55	15	snack	MAMA Cup Yen Ta Fo
56	20	snack	Lays Classic Salt 50g
57	20	snack	Lays Nori Seaweed 50g
58	20	snack	Lays Extra Barbecue 50g
59	20	snack	Lays Sour Cream Onion 50g
60	20	snack	Lays 2-in-1 Grilled Prawn
61	20	snack	Lays Rock Hot Chili Squid
62	20	snack	Lays Rock Basil Chicken
63	20	snack	Testo Potato Chips Salt
64	20	snack	Testo Potato Chips Crab Curry
65	20	snack	Testo Potato Chips Pla Sam Rot
66	20	snack	Bento Squid Snack Sweet & Spicy
67	20	snack	Bento Squid Snack Hot & Spicy
68	20	snack	Bento Squid Snack Larb
69	20	snack	Taro Fish Snack Original
70	20	snack	Taro Fish Snack BBQ
71	20	snack	Taro Fish Snack Super Spicy
72	25	snack	Tao Kae Noi Seaweed Classic
73	25	snack	Tao Kae Noi Seaweed Spicy
74	20	snack	Koh-Kae Peanuts Coconut Cream
75	20	snack	Koh-Kae Peanuts Chicken
76	20	snack	Koh-Kae Peanuts Shrimp
77	5	snack	Euro Cake Custard
78	5	snack	Euro Cake Marble
79	5	snack	Euro Cake Strawberry
80	5	snack	Euro Cake Banana
81	5	snack	Ellse Layer Cake Coconut
82	5	snack	Ellse Layer Cake Pandan
83	5	snack	Beng Beng Wafer Chocolate
84	6	snack	Tivoli Wafer Chocolate
85	6	snack	Tivoli Wafer Vanilla
86	20	snack	Pocky Strawberry
87	20	snack	Pocky Chocolate
88	20	snack	Pocky Cookies and Cream
89	20	snack	Pocky Matcha Green Tea
90	20	snack	Pocky Wholesome Blueberry
91	15	snack	Pretz Pizza Flavor
92	15	snack	Pretz Larb Flavor
93	15	snack	Pretz Corn Flavor
94	15	snack	Pretz Tom Yum Kung
95	12	snack	Cornae Corn Snack
96	12	snack	Paprika Potato Snack
97	15	snack	Hanami Prawn Crackers
98	10	snack	Roller Coaster Potato Ring BBQ
99	10	snack	Roller Coaster Potato Ring Cheese
100	20	snack	Sunbites Grain Snack Original
101	20	snack	Sunbites Grain Snack BBQ
102	12	snack	Party Sweet Potato Snack
103	10	snack	Dozo Japanese Rice Cracker
104	10	snack	Shin Mai Rice Cracker
105	30	snack	Voiz Waffle Choco
106	30	snack	Tew Pai Tong Tamarind
107	20	snack	Snack Jack Green Pea
108	20	snack	Calbee Prawn Crackers
109	20	snack	Twisties Cheese
110	20	snack	Cheetos American Cheese
111	10	snack	Halls Candy Menthol
112	10	snack	Halls Candy Honey Lemon
113	10	snack	Sugus Candy Assorted
114	12	snack	Mentos Mint Roll
115	12	snack	Mentos Fruit Roll
116	55	premium_snack	Pringles Sour Cream & Onion 107g
117	55	premium_snack	Pringles Original 107g
118	55	premium_snack	Pringles Cheesy Cheese 107g
119	55	premium_snack	Pringles Hot & Spicy 107g
120	45	premium_snack	Lays Stax Original Canister
121	45	premium_snack	Lays Stax Sour Cream Canister
122	85	premium_snack	Doritos Nacho Cheese Large
123	85	premium_snack	Doritos Spicy BBQ Large
124	120	premium_snack	Blue Diamond Almonds Roasted
125	120	premium_snack	Blue Diamond Almonds Salted
126	120	premium_snack	Blue Diamond Almonds BBQ
127	135	premium_snack	Sunkist Pistachios Roasted
128	135	premium_snack	Sunkist Pistachios Salted
129	95	premium_snack	Tong Garden Macadamia Salted
130	65	premium_snack	Koh-Kae Peanuts Can Coconut
131	65	premium_snack	Koh-Kae Peanuts Can Nori
132	150	premium_snack	Ferrero Rocher 5 Pack
133	250	premium_snack	Ferrero Rocher T16 Box
134	45	premium_snack	Kinder Bueno Bar Twin
135	45	premium_snack	Kinder Bueno White Twin
136	50	premium_snack	Nutella B-ready 2pc
137	120	premium_snack	Nutella Go Breadstick Cup
138	85	premium_snack	Ritter Sport Chocolate Milk
139	85	premium_snack	Ritter Sport Chocolate Dark
140	85	premium_snack	Ritter Sport Strawberry Yogurt
141	110	premium_snack	Lindt Excellence 70% Cocoa
142	110	premium_snack	Lindt Excellence Orange Intense
143	150	premium_snack	Meiji Macadamia Chocolate Box
144	150	premium_snack	Meiji Almond Chocolate Box
145	55	premium_snack	Loacker Wafer Napolitan 125g
146	55	premium_snack	Loacker Wafer Vanilla 125g
147	55	premium_snack	Loacker Wafer Cocoa Milk 125g
148	60	premium_snack	Pepperidge Farm Cookies Sausalito
149	60	premium_snack	Pepperidge Farm Cookies Milano
150	90	premium_snack	Oreo Box Imported Vanilla
151	90	premium_snack	Oreo Box Imported Chocolate
152	45	premium_snack	Glico Pejoy Chocolate Large
153	45	premium_snack	Glico Pejoy Matcha Large
154	180	premium_snack	Diamond Grains Granola Chocolate
155	180	premium_snack	Diamond Grains Granola Berry
156	180	premium_snack	Diamond Grains Granola Matcha
157	40	premium_snack	Diamond Grains Cup Chocolate
158	40	premium_snack	Diamond Grains Cup Berry
159	120	premium_snack	Doi Kham Dehydrated Mango
160	140	premium_snack	Doi Kham Dehydrated Strawberry
161	160	premium_snack	Doi Kham Dehydrated Durian
162	80	premium_snack	Crispy Veggie Chips Mix
163	80	premium_snack	Crispy Mushroom Snack
164	120	premium_snack	Kelloggs Cornflakes Box 150g
165	120	premium_snack	Koko Krunch Box 170g
166	95	premium_snack	Goldfish Crackers Cheddar
167	95	premium_snack	Goldfish Crackers Pizza
168	75	premium_snack	TimTam Chocolate Original
169	75	premium_snack	TimTam Dark Chocolate
170	115	premium_snack	Hershey Kisses Almond
171	115	premium_snack	Hershey Kisses Cookies Cream
172	60	premium_snack	Fishermans Friend Lemon Free
173	60	premium_snack	Fishermans Friend Mint Free
174	150	premium_snack	Haribo Goldbears Tub
175	90	premium_snack	KitKat Matcha Imported Bag
176	10	everyday goods	Blue Ballpoint Pen 0.5mm
177	10	everyday goods	Red Ballpoint Pen 0.5mm
178	10	everyday goods	Black Ballpoint Pen 0.5mm
179	15	everyday goods	University Ruled Notebook A5
180	25	everyday goods	University Ruled Notebook A4
181	35	everyday goods	Correction Tape 5mm
182	45	everyday goods	Double A Paper 40 Sheets
183	15	everyday goods	Exam Grid Paper Pack
184	20	everyday goods	Plastic Document Folder Clear
185	40	everyday goods	Staedtler 2B Pencil Set
186	15	everyday goods	Eraser Polymer
187	20	everyday goods	Small Cutter Knife
188	30	everyday goods	UHU Glue Stick
189	20	everyday goods	Face Mask 3-Ply Individual
190	25	everyday goods	Alcohol Wet Wipes
191	15	everyday goods	Post-it Notes 3x3 Yellow
192	25	everyday goods	Post-it Flags Assorted
193	45	everyday goods	Panasonic AA Batteries 4pk
194	150	everyday goods	Sandisk USB Drive 16GB
195	120	everyday goods	Wireless Mouse Basic
196	1650	everyday goods	Casio FX-991EX Scientific Calculator
197	1800	everyday goods	Engineering Drawing Instrument Kit
198	1500	everyday goods	Faculty Lab Coat Premium Cotton
199	1900	everyday goods	University Graduation Gown Deposit
200	1750	everyday goods	Fine Arts Acrylic Paint Set Pro
\.


--
--

SELECT pg_catalog.setval('public.customer_cid_seq', 1, false);


--
--

SELECT pg_catalog.setval('public.porder_oid_seq', 1, false);


--
--

SELECT pg_catalog.setval('public.product_pid_seq', 1, false);


--
--

ALTER TABLE ONLY public.customer
    ADD CONSTRAINT customer_pk PRIMARY KEY (cid);


--
--

ALTER TABLE ONLY public.placement
    ADD CONSTRAINT placement_pk PRIMARY KEY (pid, oid, cid);


--
--

ALTER TABLE ONLY public.porder
    ADD CONSTRAINT porder_pkey PRIMARY KEY (oid);


--
--

ALTER TABLE ONLY public.product
    ADD CONSTRAINT product_pkey PRIMARY KEY (pid);


--
-- PostgreSQL database dump complete
--

\unrestrict Cu3GFcueDe1UeZfVBLkeMHWgZoHF0txVYIGFCFFd2vRZ9KY4g5xA2L9ddOqtKMt


