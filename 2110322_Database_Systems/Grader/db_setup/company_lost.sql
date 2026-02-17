--
-- PostgreSQL database dump
--

-- Dumped from database version 12.19 (Debian 12.19-1.pgdg120+1)
-- Dumped by pg_dump version 12.19 (Debian 12.19-1.pgdg120+1)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

ALTER TABLE ONLY public.order_details DROP CONSTRAINT order_details_pid_fkey;
ALTER TABLE ONLY public.order_details DROP CONSTRAINT order_details_oid_fkey;
ALTER TABLE ONLY public.products DROP CONSTRAINT products_pkey;
ALTER TABLE ONLY public.orders DROP CONSTRAINT orders_pkey;
ALTER TABLE public.products ALTER COLUMN pid DROP DEFAULT;
ALTER TABLE public.orders ALTER COLUMN oid DROP DEFAULT;
ALTER TABLE public.order_details ALTER COLUMN oid DROP DEFAULT;
ALTER TABLE public.order_details ALTER COLUMN pid DROP DEFAULT;
DROP SEQUENCE public.products_pid_seq;
DROP TABLE public.products;
DROP SEQUENCE public.orders_oid_seq;
DROP TABLE public.orders;
DROP SEQUENCE public.order_details_pid_seq;
DROP SEQUENCE public.order_details_oid_seq;
DROP TABLE public.order_details;
SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: order_details; Type: TABLE; Schema: public; Owner: admin
--

CREATE TABLE public.order_details (
    pid integer NOT NULL,
    oid integer NOT NULL,
    discount double precision NOT NULL,
    quantity integer NOT NULL
);


ALTER TABLE public.order_details OWNER TO admin;

--
-- Name: order_details_oid_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE public.order_details_oid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.order_details_oid_seq OWNER TO admin;

--
-- Name: order_details_oid_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE public.order_details_oid_seq OWNED BY public.order_details.oid;


--
-- Name: order_details_pid_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE public.order_details_pid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.order_details_pid_seq OWNER TO admin;

--
-- Name: order_details_pid_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE public.order_details_pid_seq OWNED BY public.order_details.pid;


--
-- Name: orders; Type: TABLE; Schema: public; Owner: admin
--

CREATE TABLE public.orders (
    oid integer NOT NULL,
    order_date timestamp without time zone NOT NULL
);


ALTER TABLE public.orders OWNER TO admin;

--
-- Name: orders_oid_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE public.orders_oid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.orders_oid_seq OWNER TO admin;

--
-- Name: orders_oid_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE public.orders_oid_seq OWNED BY public.orders.oid;


--
-- Name: products; Type: TABLE; Schema: public; Owner: admin
--

CREATE TABLE public.products (
    pid integer NOT NULL,
    unit_price integer NOT NULL
);


ALTER TABLE public.products OWNER TO admin;

--
-- Name: products_pid_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE public.products_pid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.products_pid_seq OWNER TO admin;

--
-- Name: products_pid_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE public.products_pid_seq OWNED BY public.products.pid;


--
-- Name: order_details pid; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.order_details ALTER COLUMN pid SET DEFAULT nextval('public.order_details_pid_seq'::regclass);


--
-- Name: order_details oid; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.order_details ALTER COLUMN oid SET DEFAULT nextval('public.order_details_oid_seq'::regclass);


--
-- Name: orders oid; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.orders ALTER COLUMN oid SET DEFAULT nextval('public.orders_oid_seq'::regclass);


--
-- Name: products pid; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.products ALTER COLUMN pid SET DEFAULT nextval('public.products_pid_seq'::regclass);


--
-- Data for Name: order_details; Type: TABLE DATA; Schema: public; Owner: admin
--

COPY public.order_details (pid, oid, discount, quantity) FROM stdin;
105	25	0.15	50
106	26	0.05	30
107	27	0.1	100
108	28	0.2	200
109	29	0.25	150
111	30	0.3	120
112	31	0.05	250
113	32	0.12	300
114	33	0.08	90
115	34	0.18	60
116	35	0.2	180
117	36	0.1	110
118	37	0.05	80
119	38	0.3	200
120	39	0.07	140
121	40	0.22	170
122	41	0.1	150
123	42	0.25	250
124	43	0.18	130
125	44	0.12	90
\.


--
-- Data for Name: orders; Type: TABLE DATA; Schema: public; Owner: admin
--

COPY public.orders (oid, order_date) FROM stdin;
25	2024-12-03 00:00:00
26	2023-10-20 00:00:00
27	2022-09-15 00:00:00
28	2021-08-08 00:00:00
29	2020-07-25 00:00:00
30	2019-06-12 00:00:00
31	2018-05-30 00:00:00
32	2017-04-05 00:00:00
33	2016-03-17 00:00:00
34	2015-02-01 00:00:00
35	2024-01-19 00:00:00
36	2023-12-22 00:00:00
37	2022-11-09 00:00:00
38	2021-10-16 00:00:00
39	2020-09-08 00:00:00
40	2019-08-29 00:00:00
41	2018-07-04 00:00:00
42	2017-06-17 00:00:00
43	2016-05-25 00:00:00
44	2015-04-12 00:00:00
\.


--
-- Data for Name: products; Type: TABLE DATA; Schema: public; Owner: admin
--

COPY public.products (pid, unit_price) FROM stdin;
105	50
106	75
107	45
108	300
109	150
111	500
112	125
113	250
114	180
115	95
116	400
117	60
118	500
119	90
120	220
121	210
122	55
123	85
124	300
125	120
\.


--
-- Name: order_details_oid_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('public.order_details_oid_seq', 1, false);


--
-- Name: order_details_pid_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('public.order_details_pid_seq', 1, false);


--
-- Name: orders_oid_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('public.orders_oid_seq', 1, false);


--
-- Name: products_pid_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('public.products_pid_seq', 1, false);


--
-- Name: orders orders_pkey; Type: CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.orders
    ADD CONSTRAINT orders_pkey PRIMARY KEY (oid);


--
-- Name: products products_pkey; Type: CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.products
    ADD CONSTRAINT products_pkey PRIMARY KEY (pid);


--
-- Name: order_details order_details_oid_fkey; Type: FK CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.order_details
    ADD CONSTRAINT order_details_oid_fkey FOREIGN KEY (oid) REFERENCES public.orders(oid);


--
-- Name: order_details order_details_pid_fkey; Type: FK CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.order_details
    ADD CONSTRAINT order_details_pid_fkey FOREIGN KEY (pid) REFERENCES public.products(pid);


--
-- PostgreSQL database dump complete
--