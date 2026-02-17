--
-- PostgreSQL database dump
--

-- Dumped from database version 16.1 (Debian 16.1-1.pgdg120+1)
-- Dumped by pg_dump version 16.1

-- Started on 2024-02-08 03:17:58 UTC

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
-- TOC entry 215 (class 1259 OID 18256)
-- Name: customer; Type: TABLE; Schema: public; Owner: root
--

CREATE TABLE public.customer (
    c_id integer NOT NULL,
    c_name character varying(25) NOT NULL,
    c_address character varying(30),
    city character varying(20),
    postal_code character varying(9)
);


ALTER TABLE public.customer OWNER TO root;

--
-- TOC entry 216 (class 1259 OID 18259)
-- Name: order_line; Type: TABLE; Schema: public; Owner: root
--

CREATE TABLE public.order_line (
    o_id integer NOT NULL,
    p_id integer NOT NULL,
    o_quantity integer
);


ALTER TABLE public.order_line OWNER TO root;

--
-- TOC entry 217 (class 1259 OID 18262)
-- Name: ordert; Type: TABLE; Schema: public; Owner: root
--

CREATE TABLE public.ordert (
    o_id integer NOT NULL,
    o_date timestamp without time zone DEFAULT CURRENT_TIMESTAMP,
    c_id integer NOT NULL
);


ALTER TABLE public.ordert OWNER TO root;

--
-- TOC entry 218 (class 1259 OID 18266)
-- Name: product; Type: TABLE; Schema: public; Owner: root
--

CREATE TABLE public.product (
    p_id integer NOT NULL,
    p_desc character varying(50),
    p_finish character varying(50),
    p_price numeric(8,2)
);


ALTER TABLE public.product OWNER TO root;

--
-- TOC entry 3369 (class 0 OID 18256)
-- Dependencies: 215
-- Data for Name: customer; Type: TABLE DATA; Schema: public; Owner: root
--

INSERT INTO public.customer VALUES (1, '1', '1', '1', '1');
INSERT INTO public.customer VALUES (2, '1', '1', '1', '1');
INSERT INTO public.customer VALUES (3, '1', '1', '1', '1');
INSERT INTO public.customer VALUES (4, 'name', 'address', 'city', '12345');
INSERT INTO public.customer VALUES (5, 'name', 'address', 'city', '12345');
INSERT INTO public.customer VALUES (6, 'name', 'address', 'city', '12345');
INSERT INTO public.customer VALUES (7, 'name', 'address', 'city', '12345');
INSERT INTO public.customer VALUES (8, 'name', 'address', 'city', '12345');
INSERT INTO public.customer VALUES (9, 'name', 'address', 'city', '12345');
INSERT INTO public.customer VALUES (10, 'name', 'address', 'city', '12345');
INSERT INTO public.customer VALUES (11, 'name', 'address', 'city', '12345');
INSERT INTO public.customer VALUES (12, 'name', 'address', 'city', '12345');


--
-- TOC entry 3370 (class 0 OID 18259)
-- Dependencies: 216
-- Data for Name: order_line; Type: TABLE DATA; Schema: public; Owner: root
--



--
-- TOC entry 3371 (class 0 OID 18262)
-- Dependencies: 217
-- Data for Name: ordert; Type: TABLE DATA; Schema: public; Owner: root
--

INSERT INTO public.ordert VALUES (1, '2024-02-04 09:34:02.594223', 1);
INSERT INTO public.ordert VALUES (2, '2024-02-04 09:35:42.483659', 2);
INSERT INTO public.ordert VALUES (3, '2024-02-04 09:35:42.483659', 3);
INSERT INTO public.ordert VALUES (4, '2024-02-04 09:48:19.868749', 4);
INSERT INTO public.ordert VALUES (5, '2024-02-04 09:48:19.868749', 5);
INSERT INTO public.ordert VALUES (6, '2024-02-04 09:48:19.868749', 6);
INSERT INTO public.ordert VALUES (7, '2024-02-04 09:52:49.042569', 7);
INSERT INTO public.ordert VALUES (8, '2024-02-04 09:52:49.042569', 8);
INSERT INTO public.ordert VALUES (9, '2024-02-04 09:52:49.042569', 9);
INSERT INTO public.ordert VALUES (10, '2024-02-04 09:57:26.07352', 10);
INSERT INTO public.ordert VALUES (11, '2024-02-04 09:57:26.07352', 11);
INSERT INTO public.ordert VALUES (12, '2024-02-04 09:57:26.07352', 12);


--
-- TOC entry 3372 (class 0 OID 18266)
-- Dependencies: 218
-- Data for Name: product; Type: TABLE DATA; Schema: public; Owner: root
--

INSERT INTO public.product VALUES (1, 'cool shirt', 'white', 10.00);
INSERT INTO public.product VALUES (2, 'cool shirt', 'white', 10.00);
INSERT INTO public.product VALUES (3, 'cool shirt', 'white', 10.00);
INSERT INTO public.product VALUES (4, 'cool pants', 'very white', 10.00);
INSERT INTO public.product VALUES (5, 'cool pants', 'super white', 10.00);
INSERT INTO public.product VALUES (6, 'cool pants', 'a little white', 10.00);
INSERT INTO public.product VALUES (7, 'cool pants', 'very dark', 10.00);
INSERT INTO public.product VALUES (8, 'cool pants', 'super brown', 10.00);
INSERT INTO public.product VALUES (9, 'cool pants', 'a little green', 10.00);
INSERT INTO public.product VALUES (10, 'cool pants', 'very WHITE', 10.00);
INSERT INTO public.product VALUES (11, 'cool pants', 'super White', 10.00);
INSERT INTO public.product VALUES (12, 'cool pants', 'a little White', 10.00);


--
-- TOC entry 3216 (class 2606 OID 18270)
-- Name: customer customer_pk; Type: CONSTRAINT; Schema: public; Owner: root
--

ALTER TABLE ONLY public.customer
    ADD CONSTRAINT customer_pk PRIMARY KEY (c_id);


--
-- TOC entry 3218 (class 2606 OID 18272)
-- Name: order_line order_line_pk; Type: CONSTRAINT; Schema: public; Owner: root
--

ALTER TABLE ONLY public.order_line
    ADD CONSTRAINT order_line_pk PRIMARY KEY (o_id, p_id);


--
-- TOC entry 3220 (class 2606 OID 18274)
-- Name: ordert order_pk; Type: CONSTRAINT; Schema: public; Owner: root
--

ALTER TABLE ONLY public.ordert
    ADD CONSTRAINT order_pk PRIMARY KEY (o_id);


--
-- TOC entry 3222 (class 2606 OID 18276)
-- Name: product product_pk; Type: CONSTRAINT; Schema: public; Owner: root
--

ALTER TABLE ONLY public.product
    ADD CONSTRAINT product_pk PRIMARY KEY (p_id);


--
-- TOC entry 3225 (class 2606 OID 18277)
-- Name: ordert order_fk; Type: FK CONSTRAINT; Schema: public; Owner: root
--

ALTER TABLE ONLY public.ordert
    ADD CONSTRAINT order_fk FOREIGN KEY (c_id) REFERENCES public.customer(c_id);


--
-- TOC entry 3223 (class 2606 OID 18282)
-- Name: order_line order_line_fk1; Type: FK CONSTRAINT; Schema: public; Owner: root
--

ALTER TABLE ONLY public.order_line
    ADD CONSTRAINT order_line_fk1 FOREIGN KEY (o_id) REFERENCES public.ordert(o_id);


--
-- TOC entry 3224 (class 2606 OID 18287)
-- Name: order_line order_line_fk2; Type: FK CONSTRAINT; Schema: public; Owner: root
--

ALTER TABLE ONLY public.order_line
    ADD CONSTRAINT order_line_fk2 FOREIGN KEY (p_id) REFERENCES public.product(p_id);


-- Completed on 2024-02-08 03:17:58 UTC

--
-- PostgreSQL database dump complete
--
