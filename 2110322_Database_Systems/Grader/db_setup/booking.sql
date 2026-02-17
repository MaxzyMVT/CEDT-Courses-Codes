--
-- PostgreSQL database dump
--

-- Dumped from database version 14.15 (Debian 14.15-1.pgdg120+1)
-- Dumped by pg_dump version 14.15 (Debian 14.15-1.pgdg120+1)

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

ALTER TABLE ONLY public.bookings DROP CONSTRAINT bookings_pkey;
ALTER TABLE public.bookings ALTER COLUMN id DROP DEFAULT;
DROP SEQUENCE public.bookings_id_seq;
DROP TABLE public.bookings;
SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: bookings; Type: TABLE; Schema: public; Owner: grader_pg
--

CREATE TABLE public.bookings (
    id integer NOT NULL,
    room_type character varying(50) NOT NULL,
    check_in_date date NOT NULL,
    check_out_date date NOT NULL
);



--
-- Name: bookings_id_seq; Type: SEQUENCE; Schema: public; Owner: grader_pg
--

CREATE SEQUENCE public.bookings_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;



--
-- Name: bookings_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: grader_pg
--

ALTER SEQUENCE public.bookings_id_seq OWNED BY public.bookings.id;


--
-- Name: bookings id; Type: DEFAULT; Schema: public; Owner: grader_pg
--

ALTER TABLE ONLY public.bookings ALTER COLUMN id SET DEFAULT nextval('public.bookings_id_seq'::regclass);


--
-- Data for Name: bookings; Type: TABLE DATA; Schema: public; Owner: grader_pg
--

COPY public.bookings (id, room_type, check_in_date, check_out_date) FROM stdin;
1	Deluxe	2023-12-30	2024-01-02
2	Suite	2023-11-15	2023-11-20
3	Deluxe	2023-12-10	2023-12-15
4	Suite	2023-11-05	2023-11-10
\.


--
-- Name: bookings_id_seq; Type: SEQUENCE SET; Schema: public; Owner: grader_pg
--

SELECT pg_catalog.setval('public.bookings_id_seq', 4, true);


--
-- Name: bookings bookings_pkey; Type: CONSTRAINT; Schema: public; Owner: grader_pg
--

ALTER TABLE ONLY public.bookings
    ADD CONSTRAINT bookings_pkey PRIMARY KEY (id);


--
-- PostgreSQL database dump complete
--

