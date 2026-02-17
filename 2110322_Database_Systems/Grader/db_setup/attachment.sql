--
-- PostgreSQL database dump
--

-- Dumped from database version 12.20 (Debian 12.20-1.pgdg120+1)
-- Dumped by pg_dump version 12.20

-- Started on 2024-08-31 04:01:49 UTC

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

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- TOC entry 203 (class 1259 OID 16388)
-- Name: purchase_orders; Type: TABLE; Schema: public; Owner: admin
--

CREATE TABLE public.purchase_orders (
    id integer NOT NULL,
    customer character varying,
    order_date date,
    delivery_date date,
    quantity integer,
    total_cost numeric
);


ALTER TABLE public.purchase_orders OWNER TO admin;

--
-- TOC entry 202 (class 1259 OID 16386)
-- Name: purchase_orders_id_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE public.purchase_orders_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.purchase_orders_id_seq OWNER TO admin;

--
-- TOC entry 2987 (class 0 OID 0)
-- Dependencies: 202
-- Name: purchase_orders_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE public.purchase_orders_id_seq OWNED BY public.purchase_orders.id;


--
-- TOC entry 2851 (class 2604 OID 16391)
-- Name: purchase_orders id; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.purchase_orders ALTER COLUMN id SET DEFAULT nextval('public.purchase_orders_id_seq'::regclass);


--
-- TOC entry 2981 (class 0 OID 16388)
-- Dependencies: 203
-- Data for Name: purchase_orders; Type: TABLE DATA; Schema: public; Owner: admin
--

COPY public.purchase_orders (id, customer, order_date, delivery_date, quantity, total_cost) FROM stdin;
6	Customer A	2024-08-01	2024-08-04	100	1500
7	Customer B	2024-08-02	2024-08-05	200	3000
8	Customer C	2024-08-03	2024-08-06	150	2250
\.


--
-- TOC entry 2988 (class 0 OID 0)
-- Dependencies: 202
-- Name: purchase_orders_id_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('public.purchase_orders_id_seq', 8, true);


--
-- TOC entry 2853 (class 2606 OID 16396)
-- Name: purchase_orders purchase_orders_pkey; Type: CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.purchase_orders
    ADD CONSTRAINT purchase_orders_pkey PRIMARY KEY (id);


-- Completed on 2024-08-31 04:01:50 UTC

--
-- PostgreSQL database dump complete
--

