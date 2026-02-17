--
-- PostgreSQL database dump
--

-- Dumped from database version 14.10 (Ubuntu 14.10-0ubuntu0.22.04.1)
-- Dumped by pg_dump version 14.10 (Ubuntu 14.10-0ubuntu0.22.04.1)

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

ALTER TABLE ONLY public.orders DROP CONSTRAINT order_pkey;
ALTER TABLE ONLY public.orders DROP CONSTRAINT dessert_fkey;
ALTER TABLE ONLY public.orders DROP CONSTRAINT customer_fkey;
ALTER TABLE public.orders ALTER COLUMN id DROP DEFAULT;
DROP SEQUENCE public.order_id_seq;
DROP TABLE public.orders;

ALTER TABLE ONLY public.desserts DROP CONSTRAINT dessert_pkey;
ALTER TABLE public.desserts ALTER COLUMN id DROP DEFAULT;
DROP SEQUENCE public.dessert_id_seq;
DROP TABLE public.desserts;

ALTER TABLE ONLY public.customers DROP CONSTRAINT customer_pkey;
ALTER TABLE public.customers ALTER COLUMN id DROP DEFAULT;
DROP SEQUENCE public.customer_id_seq;
DROP TABLE public.customers;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: dessert; Type: TABLE; Schema: public; Owner: grader_pg
--

CREATE TABLE public.desserts (
    id integer NOT NULL,
    name character varying,
    price integer
);



--
-- Name: dessert_id_seq; Type: SEQUENCE; Schema: public; Owner: grader_pg
--

CREATE SEQUENCE public.dessert_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;



--
-- Name: dessert_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: grader_pg
--

ALTER SEQUENCE public.dessert_id_seq OWNED BY public.desserts.id;


--
-- Name: dessert id; Type: DEFAULT; Schema: public; Owner: grader_pg
--

ALTER TABLE ONLY public.desserts ALTER COLUMN id SET DEFAULT nextval('public.dessert_id_seq'::regclass);


--
-- Data for Name: dessert; Type: TABLE DATA; Schema: public; Owner: grader_pg
--

COPY public.desserts (id, name, price) FROM stdin;
1	chocolate	20
2	cake	100
3	croissant	120
\.


--
-- Name: dessert_id_seq; Type: SEQUENCE SET; Schema: public; Owner: grader_pg
--

SELECT pg_catalog.setval('public.dessert_id_seq', 4, true);


--
-- Name: dessert dessert_pkey; Type: CONSTRAINT; Schema: public; Owner: grader_pg
--

ALTER TABLE ONLY public.desserts
    ADD CONSTRAINT dessert_pkey PRIMARY KEY (id);


--
-- Name: customer; Type: TABLE; Schema: public; Owner: grader_pg
--

CREATE TABLE public.customers (
    id integer NOT NULL,
    name character varying
);



--
-- Name: customer_id_seq; Type: SEQUENCE; Schema: public; Owner: grader_pg
--

CREATE SEQUENCE public.customer_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;



--
-- Name: customer_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: grader_pg
--

ALTER SEQUENCE public.customer_id_seq OWNED BY public.customers.id;


--
-- Name: customer id; Type: DEFAULT; Schema: public; Owner: grader_pg
--

ALTER TABLE ONLY public.customers ALTER COLUMN id SET DEFAULT nextval('public.customer_id_seq'::regclass);


--
-- Data for Name: customer; Type: TABLE DATA; Schema: public; Owner: grader_pg
--

COPY public.customers (id, name) FROM stdin;
1	Roseheart
2	Clover
3	Spade
4	Trappola
\.


--
-- Name: customer_id_seq; Type: SEQUENCE SET; Schema: public; Owner: grader_pg
--

SELECT pg_catalog.setval('public.customer_id_seq', 4, true);


--
-- Name: customer customer_pkey; Type: CONSTRAINT; Schema: public; Owner: grader_pg
--

ALTER TABLE ONLY public.customers
    ADD CONSTRAINT customer_pkey PRIMARY KEY (id);


--
-- Name: order; Type: TABLE; Schema: public; Owner: grader_pg
--

CREATE TABLE public.orders (
    id integer NOT NULL,
    d_id integer NOT NULL,
    amount integer,
    c_id integer NOT NULL
);



--
-- Name: order_id_seq; Type: SEQUENCE; Schema: public; Owner: grader_pg
--

CREATE SEQUENCE public.order_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;



--
-- Name: order_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: grader_pg
--

ALTER SEQUENCE public.order_id_seq OWNED BY public.orders.id;


--
-- Name: order id; Type: DEFAULT; Schema: public; Owner: grader_pg
--

ALTER TABLE ONLY public.orders ALTER COLUMN id SET DEFAULT nextval('public.order_id_seq'::regclass);


--
-- Data for Name: order; Type: TABLE DATA; Schema: public; Owner: grader_pg
--

COPY public.orders (id, d_id, amount, c_id) FROM stdin;
1	1	6	1
2	1	10	2
3	2	12	4
4	3	5	3
5	2	6	3
\.


--
-- Name: order_id_seq; Type: SEQUENCE SET; Schema: public; Owner: grader_pg
--

SELECT pg_catalog.setval('public.order_id_seq', 6, true);


--
-- Name: order order_pkey; Type: CONSTRAINT; Schema: public; Owner: grader_pg
--

ALTER TABLE ONLY public.orders
    ADD CONSTRAINT order_pkey PRIMARY KEY (id),
    ADD CONSTRAINT customer_fkey FOREIGN KEY (c_id) REFERENCES public.customers(id),
    ADD CONSTRAINT dessert_fkey FOREIGN KEY (d_id) REFERENCES public.desserts(id);

--
-- PostgreSQL database dump complete
--
