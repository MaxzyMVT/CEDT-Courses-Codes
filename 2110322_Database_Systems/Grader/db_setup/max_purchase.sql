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

ALTER TABLE ONLY public.invoice DROP CONSTRAINT invoice_pkey;
ALTER TABLE ONLY public.invoice DROP CONSTRAINT invoice_fkey;
ALTER TABLE public.invoice ALTER COLUMN id DROP DEFAULT;
DROP SEQUENCE public.invoice_id_seq;
DROP TABLE public.invoice;

ALTER TABLE ONLY public.customer DROP CONSTRAINT customer_pkey;
ALTER TABLE public.customer ALTER COLUMN cus_id DROP DEFAULT;
DROP SEQUENCE public.customer_id_seq;
DROP TABLE public.customer;
SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: customer; Type: TABLE; Schema: public; Owner: grader_pg
--

CREATE TABLE public.customer (
    cus_id integer NOT NULL,
    first_name character varying(255),
    last_name character varying(255)
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

ALTER SEQUENCE public.customer_id_seq OWNED BY public.customer.cus_id;


--
-- Name: customer id; Type: DEFAULT; Schema: public; Owner: grader_pg
--

ALTER TABLE ONLY public.customer ALTER COLUMN cus_id SET DEFAULT nextval('public.customer_id_seq'::regclass);


--
-- Data for Name: customer; Type: TABLE DATA; Schema: public; Owner: grader_pg
--

INSERT INTO public.customer (cus_id, first_name, last_name) VALUES 
(1, 'suppawich', 'tawornpichayachai'),
(2, 'duangdao', 'wichadakul'),
(3, 'taratip', 'suwannasart'),
(4, 'chotirat', 'ratanamahatana'),
(5, 'proadpran', 'punyabukkana');


--
-- Name: customer_id_seq; Type: SEQUENCE SET; Schema: public; Owner: grader_pg
--

SELECT pg_catalog.setval('public.customer_id_seq', 4, true);


--
-- Name: customer customer_pkey; Type: CONSTRAINT; Schema: public; Owner: grader_pg
--

ALTER TABLE ONLY public.customer ADD CONSTRAINT customer_pkey PRIMARY KEY (cus_id);

--
-- Name: invoice; Type: TABLE; Schema: public; Owner: grader_pg
--

CREATE TABLE public.invoice (
    id integer NOT NULL,
    cus_id integer NOT NULL,
    total_spent double precision,
    transaction_date character varying(100)
);



--
-- Name: invoice_id_seq; Type: SEQUENCE; Schema: public; Owner: grader_pg
--

CREATE SEQUENCE public.invoice_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;



--
-- Name: invoice_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: grader_pg
--

ALTER SEQUENCE public.invoice_id_seq OWNED BY public.invoice.id;


--
-- Name: invoice id; Type: DEFAULT; Schema: public; Owner: grader_pg
--

ALTER TABLE ONLY public.invoice ALTER COLUMN id SET DEFAULT nextval('public.invoice_id_seq'::regclass);


--
-- Data for Name: invoice; Type: TABLE DATA; Schema: public; Owner: grader_pg
--

INSERT INTO public.invoice (id, cus_id, total_spent, transaction_date) VALUES 
(1, 1, 2000.00, '2024-08-23'),
(2, 2, 1000.00, '2024-08-24'),
(3, 2, 2100.00, '2024-08-25'),
(4, 3, 2200.00, '2024-08-25'),
(5, 4, 1300.00, '2024-08-25'),
(6, 4, 1400.00, '2024-08-26'),
(7, 5, 1450.00, '2024-08-26'),
(8, 5, 1350.00, '2024-08-27'),
(9, 1, 500.00, '2024-08-28'),
(10, 1, 600.00, '2024-08-28'),
(11, 3, 900.00, '2024-08-29');



--
-- Name: invoice_id_seq; Type: SEQUENCE SET; Schema: public; Owner: grader_pg
--

SELECT pg_catalog.setval('public.invoice_id_seq', 4, true);


--
-- Name: invoice invoice_pkey; Type: CONSTRAINT; Schema: public; Owner: grader_pg
--

ALTER TABLE ONLY public.invoice ADD CONSTRAINT invoice_pkey PRIMARY KEY (id);

--
-- Name: invoice invoice_fkey; Type: CONSTRAINT; Schema: public; Owner: grader_pg
--

ALTER TABLE ONLY public.invoice ADD CONSTRAINT invoice_fkey FOREIGN KEY (cus_id) REFERENCES public.customer(cus_id);


--
-- PostgreSQL database dump complete
--
