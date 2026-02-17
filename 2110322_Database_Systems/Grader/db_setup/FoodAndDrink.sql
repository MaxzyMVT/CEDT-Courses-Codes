--
-- PostgreSQL database dump
--

-- Dumped from database version 12.20 (Debian 12.20-1.pgdg120+1)
-- Dumped by pg_dump version 16.4

-- Started on 2024-08-31 20:15:54

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
-- TOC entry 202 (class 1259 OID 16385)
-- Name: product; Type: TABLE; Schema: public; Owner: admin
--

CREATE TABLE public.product (
    id integer NOT NULL,
    name character varying,
    category_name character varying,
    unit_price integer
);


ALTER TABLE public.product OWNER TO admin;

--
-- TOC entry 2974 (class 0 OID 16385)
-- Dependencies: 202
-- Data for Name: product; Type: TABLE DATA; Schema: public; Owner: admin
--

COPY public.product (id, name, category_name, unit_price) FROM stdin;
1	Noodle	food	23
2	Hamburger	food	2500
3	Singha	drink	3000
4	Condominium	house	100000
5	Tequila	drink	5555
\.


-- Completed on 2024-08-31 20:15:54

--
-- PostgreSQL database dump complete
--

