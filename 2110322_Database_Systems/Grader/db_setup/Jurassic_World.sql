--
-- PostgreSQL database dump
--

-- Dumped from database version 18.0 (Debian 18.0-1.pgdg13+3)
-- Dumped by pg_dump version 18.0 (Debian 18.0-1.pgdg13+3)

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET transaction_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- Name: public; Type: SCHEMA; Schema: -; Owner: grader_pg
--

-- *not* creating schema, since initdb creates it



--
-- Name: SCHEMA public; Type: COMMENT; Schema: -; Owner: grader_pg
--

COMMENT ON SCHEMA public IS '';


SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- Name: dinosaurs; Type: TABLE; Schema: public; Owner: grader_pg
--

CREATE TABLE public.dinosaurs (
    id integer NOT NULL,
    dino_name character varying NOT NULL,
    dino_type character varying NOT NULL,
    amount integer NOT NULL
);



--
-- Data for Name: dinosaurs; Type: TABLE DATA; Schema: public; Owner: grader_pg
--

COPY public.dinosaurs (id, dino_name, dino_type, amount) FROM stdin;
1	Alpha	aquatic	25
2	Alpha	aquatic	15
3	Beta	aquatic	40
4	Rex	carnivore	39
5	Triceratops	herbivore	38
6	Pteranodon	flying	5
\.


--
-- Name: SCHEMA public; Type: ACL; Schema: -; Owner: grader_pg
--

REVOKE USAGE ON SCHEMA public FROM PUBLIC;


--
-- PostgreSQL database dump complete
--


