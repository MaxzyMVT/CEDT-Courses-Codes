--
-- PostgreSQL database dump
--

-- Dumped from database version 12.22 (Debian 12.22-1.pgdg120+1)
-- Dumped by pg_dump version 12.22 (Debian 12.22-1.pgdg120+1)

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

ALTER TABLE ONLY public.task DROP CONSTRAINT task_aid_fkey;
ALTER TABLE ONLY public.submit DROP CONSTRAINT submit_tid_fkey;
ALTER TABLE ONLY public.submit DROP CONSTRAINT submit_cid_fkey;
ALTER TABLE ONLY public.task DROP CONSTRAINT task_pkey;
ALTER TABLE ONLY public.submit DROP CONSTRAINT submit_pkey;
ALTER TABLE ONLY public.contestant DROP CONSTRAINT contestant_pkey;
ALTER TABLE ONLY public.author DROP CONSTRAINT author_pkey;
ALTER TABLE public.task ALTER COLUMN tid DROP DEFAULT;
ALTER TABLE public.contestant ALTER COLUMN cid DROP DEFAULT;
ALTER TABLE public.author ALTER COLUMN aid DROP DEFAULT;
DROP SEQUENCE public.task_tid_seq;
DROP TABLE public.task;
DROP TABLE public.submit;
DROP SEQUENCE public.contestant_cid_seq;
DROP TABLE public.contestant;
DROP SEQUENCE public.author_aid_seq;
DROP TABLE public.author;
SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: author; Type: TABLE; Schema: public; Owner: admin
--

CREATE TABLE public.author (
    aid integer NOT NULL,
    aname character varying(255)
);


ALTER TABLE public.author OWNER TO admin;

--
-- Name: author_aid_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE public.author_aid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.author_aid_seq OWNER TO admin;

--
-- Name: author_aid_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE public.author_aid_seq OWNED BY public.author.aid;


--
-- Name: contestant; Type: TABLE; Schema: public; Owner: admin
--

CREATE TABLE public.contestant (
    cid integer NOT NULL,
    cname character varying(255)
);


ALTER TABLE public.contestant OWNER TO admin;

--
-- Name: contestant_cid_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE public.contestant_cid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.contestant_cid_seq OWNER TO admin;

--
-- Name: contestant_cid_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE public.contestant_cid_seq OWNED BY public.contestant.cid;


--
-- Name: submit; Type: TABLE; Schema: public; Owner: admin
--

CREATE TABLE public.submit (
    cid integer NOT NULL,
    tid integer NOT NULL,
    score integer
);


ALTER TABLE public.submit OWNER TO admin;

--
-- Name: task; Type: TABLE; Schema: public; Owner: admin
--

CREATE TABLE public.task (
    tid integer NOT NULL,
    tname character varying(255),
    aid integer NOT NULL
);


ALTER TABLE public.task OWNER TO admin;

--
-- Name: task_tid_seq; Type: SEQUENCE; Schema: public; Owner: admin
--

CREATE SEQUENCE public.task_tid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE public.task_tid_seq OWNER TO admin;

--
-- Name: task_tid_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: admin
--

ALTER SEQUENCE public.task_tid_seq OWNED BY public.task.tid;


--
-- Name: author aid; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.author ALTER COLUMN aid SET DEFAULT nextval('public.author_aid_seq'::regclass);


--
-- Name: contestant cid; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.contestant ALTER COLUMN cid SET DEFAULT nextval('public.contestant_cid_seq'::regclass);


--
-- Name: task tid; Type: DEFAULT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.task ALTER COLUMN tid SET DEFAULT nextval('public.task_tid_seq'::regclass);


--
-- Data for Name: author; Type: TABLE DATA; Schema: public; Owner: admin
--

COPY public.author (aid, aname) FROM stdin;
31	Alex
32	Ben
33	Carol
34	David
35	Eve
36	Frank
\.


--
-- Data for Name: contestant; Type: TABLE DATA; Schema: public; Owner: admin
--

COPY public.contestant (cid, cname) FROM stdin;
11	John
12	Jane
13	Jack
14	Jill
15	Jim
16	Judy
17	Joe
\.


--
-- Data for Name: submit; Type: TABLE DATA; Schema: public; Owner: admin
--

COPY public.submit (cid, tid, score) FROM stdin;
11	21	100
11	22	100
11	23	100
11	24	100
11	25	79
11	26	100
12	21	100
12	22	100
12	23	62
12	24	63
12	25	100
12	26	100
13	21	100
13	22	100
13	23	100
13	24	100
13	25	100
13	26	100
14	21	100
14	22	15
14	23	100
14	24	100
14	25	100
14	26	100
15	21	100
15	22	100
15	23	100
15	24	100
15	25	100
15	26	100
16	21	97
16	22	100
16	23	7
16	24	100
16	25	100
16	26	69
17	21	16
17	22	97
17	23	100
17	24	90
17	25	55
17	26	100
\.


--
-- Data for Name: task; Type: TABLE DATA; Schema: public; Owner: admin
--

COPY public.task (tid, tname, aid) FROM stdin;
21	A	31
22	B	32
23	C	33
24	D	34
25	E	35
26	F	36
\.


--
-- Name: author_aid_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('public.author_aid_seq', 1, false);


--
-- Name: contestant_cid_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('public.contestant_cid_seq', 1, false);


--
-- Name: task_tid_seq; Type: SEQUENCE SET; Schema: public; Owner: admin
--

SELECT pg_catalog.setval('public.task_tid_seq', 1, false);


--
-- Name: author author_pkey; Type: CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.author
    ADD CONSTRAINT author_pkey PRIMARY KEY (aid);


--
-- Name: contestant contestant_pkey; Type: CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.contestant
    ADD CONSTRAINT contestant_pkey PRIMARY KEY (cid);


--
-- Name: submit submit_pkey; Type: CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.submit
    ADD CONSTRAINT submit_pkey PRIMARY KEY (cid, tid);


--
-- Name: task task_pkey; Type: CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.task
    ADD CONSTRAINT task_pkey PRIMARY KEY (tid);


--
-- Name: submit submit_cid_fkey; Type: FK CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.submit
    ADD CONSTRAINT submit_cid_fkey FOREIGN KEY (cid) REFERENCES public.contestant(cid) ON DELETE CASCADE;


--
-- Name: submit submit_tid_fkey; Type: FK CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.submit
    ADD CONSTRAINT submit_tid_fkey FOREIGN KEY (tid) REFERENCES public.task(tid) ON DELETE CASCADE;


--
-- Name: task task_aid_fkey; Type: FK CONSTRAINT; Schema: public; Owner: admin
--

ALTER TABLE ONLY public.task
    ADD CONSTRAINT task_aid_fkey FOREIGN KEY (aid) REFERENCES public.author(aid) ON DELETE CASCADE;


--
-- PostgreSQL database dump complete
--
