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

ALTER TABLE ONLY public.product_sales DROP CONSTRAINT product_sales_pid_fkey;
ALTER TABLE ONLY public.product_sales DROP CONSTRAINT product_sales_pkey;
ALTER TABLE ONLY public.product DROP CONSTRAINT product_pkey;
ALTER TABLE public.product_sales ALTER COLUMN sale_id DROP DEFAULT;
ALTER TABLE public.product ALTER COLUMN pid DROP DEFAULT;
DROP SEQUENCE public.product_sales_sale_id_seq;
DROP TABLE public.product_sales;
DROP SEQUENCE public.product_pid_seq;
DROP TABLE public.product;
SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: product; Type: TABLE; Schema: public; Owner: admin
--

CREATE TABLE public.product (
    pid integer NOT NULL,
    pname text NOT NULL,
    pprice numeric(10,2) NOT NULL
);


ALTER TABLE public.product OWNER TO admin;

--
-- Name: product_pid_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE public.product_pid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.product_pid_seq OWNER TO admin;

--
-- Name: product_pid_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE public.product_pid_seq OWNED BY public.product.pid;


--
-- Name: product_sales; Type: TABLE; Schema: public; Owner: admin
--

CREATE TABLE public.product_sales (
    sale_id integer NOT NULL,
    pid integer NOT NULL,
    quantity_sold integer NOT NULL,
    sale_date timestamp without time zone DEFAULT CURRENT_TIMESTAMP,
    CONSTRAINT product_sales_quantity_sold_check CHECK ((quantity_sold >= 0))
);


ALTER TABLE public.product_sales OWNER TO admin;

--
-- Name: product_sales_sale_id_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE public.product_sales_sale_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.product_sales_sale_id_seq OWNER TO admin;

--
-- Name: product_sales_sale_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE public.product_sales_sale_id_seq OWNED BY public.product_sales.sale_id;


--
-- Name: product pid; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.product ALTER COLUMN pid SET DEFAULT nextval('public.product_pid_seq'::regclass);


--
-- Name: product_sales sale_id; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.product_sales ALTER COLUMN sale_id SET DEFAULT nextval('public.product_sales_sale_id_seq'::regclass);


--
-- Data for Name: product; Type: TABLE DATA; Schema: public; Owner: admin
--

COPY public.product (pid, pname, pprice) FROM stdin;
1	Rolix	50000.00
2	Patik	10000.00
3	Swaz	1000.00
4	Viercel	7000.00
5	Seino	20000.00
6	Philia	4000.00
\.


--
-- Data for Name: product_sales; Type: TABLE DATA; Schema: public; Owner: admin
--

COPY public.product_sales (sale_id, pid, quantity_sold, sale_date) FROM stdin;
1	1	200	2022-01-01 00:00:01
2	1	43	2024-12-31 00:00:01
3	2	17	2025-01-01 00:00:01
4	3	56	2019-11-23 00:00:01
5	3	56	2023-12-31 00:00:01
6	4	49	2022-12-31 00:00:01
7	4	49	2024-12-31 00:00:01
8	5	44	2025-01-01 00:00:01
\.


--
-- Name: product_pid_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('public.product_pid_seq', 6, true);


--
-- Name: product_sales_sale_id_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('public.product_sales_sale_id_seq', 8, true);


--
-- Name: product product_pkey; Type: CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.product
    ADD CONSTRAINT product_pkey PRIMARY KEY (pid);


--
-- Name: product_sales product_sales_pkey; Type: CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.product_sales
    ADD CONSTRAINT product_sales_pkey PRIMARY KEY (sale_id);


--
-- Name: product_sales product_sales_pid_fkey; Type: FK CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.product_sales
    ADD CONSTRAINT product_sales_pid_fkey FOREIGN KEY (pid) REFERENCES public.product(pid) ON DELETE CASCADE;


--
-- PostgreSQL database dump complete
--
