--
-- PostgreSQL database dump
--

-- Dumped from database version 16.1 (Debian 16.1-1.pgdg120+1)
-- Dumped by pg_dump version 16.1

-- Started on 2024-02-08 04:43:06 UTC

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
-- TOC entry 216 (class 1259 OID 57374)
-- Name: playlist; Type: TABLE; Schema: public; Owner: root
--

CREATE TABLE public.playlist (
    id integer NOT NULL,
    name character varying(255),
    createdat timestamp without time zone
);


ALTER TABLE public.playlist OWNER TO root;

--
-- TOC entry 215 (class 1259 OID 57367)
-- Name: song; Type: TABLE; Schema: public; Owner: root
--

CREATE TABLE public.song (
    id integer NOT NULL,
    genre character varying(255),
    name character varying(255),
    duration integer,
    view_count integer,
    artist character varying(255)
);


ALTER TABLE public.song OWNER TO root;

--
-- TOC entry 217 (class 1259 OID 57379)
-- Name: songinplaylist; Type: TABLE; Schema: public; Owner: root
--

CREATE TABLE public.songinplaylist (
    sid integer NOT NULL,
    pid integer NOT NULL
);


ALTER TABLE public.songinplaylist OWNER TO root;

--
-- TOC entry 3364 (class 0 OID 57374)
-- Dependencies: 216
-- Data for Name: playlist; Type: TABLE DATA; Schema: public; Owner: root
--



--
-- TOC entry 3363 (class 0 OID 57367)
-- Dependencies: 215
-- Data for Name: song; Type: TABLE DATA; Schema: public; Owner: root
--

INSERT INTO public.song VALUES (1, 'Pop', 'Pop1', 120, 300, 'Artist1');
INSERT INTO public.song VALUES (3, 'Pop', 'Pop3', 120, 600, 'Artist1');
INSERT INTO public.song VALUES (2, 'Pop', 'Pop2', 120, 300, 'Artist2');
INSERT INTO public.song VALUES (4, 'Rock', 'Rock1', 180, 400, 'Artist3');
INSERT INTO public.song VALUES (5, 'Rock', 'Rock2', 240, 500, 'Artist3');
INSERT INTO public.song VALUES (6, 'Rock', 'Rock3', 180, 400, 'Artist3');


--
-- TOC entry 3365 (class 0 OID 57379)
-- Dependencies: 217
-- Data for Name: songinplaylist; Type: TABLE DATA; Schema: public; Owner: root
--



--
-- TOC entry 3215 (class 2606 OID 57378)
-- Name: playlist playlist_pkey; Type: CONSTRAINT; Schema: public; Owner: root
--

ALTER TABLE ONLY public.playlist
    ADD CONSTRAINT playlist_pkey PRIMARY KEY (id);


--
-- TOC entry 3211 (class 2606 OID 57373)
-- Name: song song_pkey; Type: CONSTRAINT; Schema: public; Owner: root
--

ALTER TABLE ONLY public.song
    ADD CONSTRAINT song_pkey PRIMARY KEY (id);


--
-- TOC entry 3217 (class 2606 OID 57383)
-- Name: songinplaylist songinplaylist_pkey; Type: CONSTRAINT; Schema: public; Owner: root
--

ALTER TABLE ONLY public.songinplaylist
    ADD CONSTRAINT songinplaylist_pkey PRIMARY KEY (sid, pid);


--
-- TOC entry 3213 (class 2606 OID 57395)
-- Name: song uq_value; Type: CONSTRAINT; Schema: public; Owner: root
--

ALTER TABLE ONLY public.song
    ADD CONSTRAINT uq_value UNIQUE (name, artist);


--
-- TOC entry 3218 (class 2606 OID 57389)
-- Name: songinplaylist fk_playlist; Type: FK CONSTRAINT; Schema: public; Owner: root
--

ALTER TABLE ONLY public.songinplaylist
    ADD CONSTRAINT fk_playlist FOREIGN KEY (pid) REFERENCES public.playlist(id);


--
-- TOC entry 3219 (class 2606 OID 57384)
-- Name: songinplaylist fk_song; Type: FK CONSTRAINT; Schema: public; Owner: root
--

ALTER TABLE ONLY public.songinplaylist
    ADD CONSTRAINT fk_song FOREIGN KEY (sid) REFERENCES public.song(id);


-- Completed on 2024-02-08 04:43:06 UTC

--
-- PostgreSQL database dump complete
--

