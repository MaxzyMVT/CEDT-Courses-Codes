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

ALTER TABLE ONLY public.work_for DROP CONSTRAINT work_for_h_id_fkey;
ALTER TABLE ONLY public.work_for DROP CONSTRAINT work_for_d_id_fkey;
ALTER TABLE ONLY public.work_for DROP CONSTRAINT work_for_pkey;
ALTER TABLE ONLY public.hospital DROP CONSTRAINT hospital_pkey;
ALTER TABLE ONLY public.doctor DROP CONSTRAINT doctor_pkey;
ALTER TABLE public.hospital ALTER COLUMN h_id DROP DEFAULT;
ALTER TABLE public.doctor ALTER COLUMN d_id DROP DEFAULT;
DROP TABLE public.work_for;
DROP SEQUENCE public.hospital_h_id_seq;
DROP TABLE public.hospital;
DROP SEQUENCE public.doctor_d_id_seq;
DROP TABLE public.doctor;
SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: doctor; Type: TABLE; Schema: public; Owner: admin
--

CREATE TABLE public.doctor (
    d_id integer NOT NULL,
    dname character varying(255),
    dage integer
);


ALTER TABLE public.doctor OWNER TO admin;

--
-- Name: doctor_d_id_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE public.doctor_d_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.doctor_d_id_seq OWNER TO admin;

--
-- Name: doctor_d_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE public.doctor_d_id_seq OWNED BY public.doctor.d_id;


--
-- Name: hospital; Type: TABLE; Schema: public; Owner: admin
--

CREATE TABLE public.hospital (
    h_id integer NOT NULL,
    hname character varying(255),
    address character varying(255)
);


ALTER TABLE public.hospital OWNER TO admin;

--
-- Name: hospital_h_id_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE public.hospital_h_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.hospital_h_id_seq OWNER TO admin;

--
-- Name: hospital_h_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE public.hospital_h_id_seq OWNED BY public.hospital.h_id;


--
-- Name: work_for; Type: TABLE; Schema: public; Owner: admin
--

CREATE TABLE public.work_for (
    d_id integer NOT NULL,
    h_id integer NOT NULL
);


ALTER TABLE public.work_for OWNER TO admin;

--
-- Name: doctor d_id; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.doctor ALTER COLUMN d_id SET DEFAULT nextval('public.doctor_d_id_seq'::regclass);


--
-- Name: hospital h_id; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.hospital ALTER COLUMN h_id SET DEFAULT nextval('public.hospital_h_id_seq'::regclass);


--
-- Data for Name: doctor; Type: TABLE DATA; Schema: public; Owner: admin
--

COPY public.doctor (d_id, dname, dage) FROM stdin;
1	Charles	45
2	Carlos	45
3	Clara	20
4	Cathy	52
5	Adrian	55
\.


--
-- Data for Name: hospital; Type: TABLE DATA; Schema: public; Owner: admin
--

COPY public.hospital (h_id, hname, address) FROM stdin;
1	City_Hospital	Downtown
2	Green_Clinic	Uptown
\.


--
-- Data for Name: work_for; Type: TABLE DATA; Schema: public; Owner: admin
--

COPY public.work_for (d_id, h_id) FROM stdin;
4	2
\.


--
-- Name: doctor_d_id_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('public.doctor_d_id_seq', 1, false);


--
-- Name: hospital_h_id_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('public.hospital_h_id_seq', 1, false);


--
-- Name: doctor doctor_pkey; Type: CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.doctor
    ADD CONSTRAINT doctor_pkey PRIMARY KEY (d_id);


--
-- Name: hospital hospital_pkey; Type: CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.hospital
    ADD CONSTRAINT hospital_pkey PRIMARY KEY (h_id);


--
-- Name: work_for work_for_pkey; Type: CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.work_for
    ADD CONSTRAINT work_for_pkey PRIMARY KEY (d_id, h_id);


--
-- Name: work_for work_for_d_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.work_for
    ADD CONSTRAINT work_for_d_id_fkey FOREIGN KEY (d_id) REFERENCES public.doctor(d_id) ON DELETE CASCADE;


--
-- Name: work_for work_for_h_id_fkey; Type: FK CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.work_for
    ADD CONSTRAINT work_for_h_id_fkey FOREIGN KEY (h_id) REFERENCES public.hospital(h_id) ON DELETE CASCADE;


--
-- PostgreSQL database dump complete
--
