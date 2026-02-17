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

ALTER TABLE ONLY public.student DROP CONSTRAINT student_pkey;
ALTER TABLE public.student ALTER COLUMN id DROP DEFAULT;
DROP SEQUENCE public.student_id_seq;
DROP TABLE public.student;
SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: student; Type: TABLE; Schema: public; Owner: grader_pg
--

CREATE TABLE public.student (
    id integer NOT NULL,
    name character varying,
    score integer
);



--
-- Name: student_id_seq; Type: SEQUENCE; Schema: public; Owner: grader_pg
--

CREATE SEQUENCE public.student_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;



--
-- Name: student_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: grader_pg
--

ALTER SEQUENCE public.student_id_seq OWNED BY public.student.id;


--
-- Name: student id; Type: DEFAULT; Schema: public; Owner: grader_pg
--

ALTER TABLE ONLY public.student ALTER COLUMN id SET DEFAULT nextval('public.student_id_seq'::regclass);


--
-- Data for Name: student; Type: TABLE DATA; Schema: public; Owner: grader_pg
--

COPY public.student (id, name, score) FROM stdin;
1	nattee	88
2	somying	88
3	somchai	88
4	asdf	88
\.


--
-- Name: student_id_seq; Type: SEQUENCE SET; Schema: public; Owner: grader_pg
--

SELECT pg_catalog.setval('public.student_id_seq', 4, true);


--
-- Name: student student_pkey; Type: CONSTRAINT; Schema: public; Owner: grader_pg
--

ALTER TABLE ONLY public.student
    ADD CONSTRAINT student_pkey PRIMARY KEY (id);


--
-- PostgreSQL database dump complete
--
