--
-- PostgreSQL database dump
--

-- Dumped from database version 18.1 (Debian 18.1-1.pgdg13+2)
-- Dumped by pg_dump version 18.1 (Debian 18.1-1.pgdg13+2)

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

SET default_tablespace = '';

SET default_table_access_method = heap;

--
--

CREATE TABLE public.blog (
    bid integer NOT NULL,
    title text NOT NULL,
    body text NOT NULL
);



--
--

CREATE SEQUENCE public.blog_bid_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;



--
--

ALTER SEQUENCE public.blog_bid_seq OWNED BY public.blog.bid;


--
--

ALTER TABLE ONLY public.blog ALTER COLUMN bid SET DEFAULT nextval('public.blog_bid_seq'::regclass);


--
--

COPY public.blog (bid, title, body) FROM stdin;
1	Getting Started with Python	Python is an interpreted, high-level, general-purpose programming language. Its design philosophy emphasizes code readability with the use of significant indentation. It is perfect for beginners.
2	Understanding Memory Leaks	A memory leak is a type of resource leak that occurs when a computer program incorrectly manages memory allocations in such a way that memory which is no longer needed is not released.
3	Daily Standup Notes - Jan 24	We discussed the backend migration. The API endpoints are returning 404 errors on the staging environment. Need to check the Nginx configs.
4	Weird Server Logs	I was digging through the /var/log/syslog file and found some garbage data. One line just said flag{e10adc3949ba59abbe56e057f20f883e} which looks like a corrupted md5 hash or something. 
5	Review of the new mechanical keyboard	The tactile feedback is amazing, but the clicky sound might annoy my coworkers. The actuation force is 45g, standard for Cherry MX Browns.
6	Docker vs Kubernetes	While Docker is a containerization platform, Kubernetes is a container orchestration platform. They are often used together, not as direct alternatives.
7	Debugging 101	Always check your variables. I spent three hours debugging a loop only to realize I was iterating over the wrong array index.
8	Recipe for great coffee	You need freshly ground beans. Don't use boiling water; aim for around 93 degrees Celsius to avoid burning the coffee.
9	API Documentation Draft	Ensure all endpoints require authentication. The header should contain the Bearer token. Example response 200 OK.
10	Legacy Code Horror	I opened the legacy module today. There were no comments, variables were named a, b, and c, and there was a hardcoded string FLAG{52g23s... just kidding that is not the format.
11	Understanding Big O Notation	Big O notation is a mathematical notation that describes the limiting behavior of a function when the argument tends towards a particular value or infinity.
12	Security Best Practices	Never commit secrets to git. We had an incident last year where a dev pushed a config file containing FLAG{cfcd208495d565ef66e7dff9f98764da} to a public repository.
13	CSS Centering Tricks	Flexbox has made centering things much easier. Just use display: flex, justify-content: center, and align-items: center.
14	My vimrc configuration	I mapped the leader key to space. It makes triggering plugins much faster. Also, relative line numbers are a game changer.
15	Introduction to Rust	Rust is a multi-paradigm programming language designed for performance and safety, especially safe concurrency. It enforces memory safety without a garbage collector.
16	Network Topologies	Star topology is the most common in LANs. Every node connects to a central network device like a switch or hub.
17	Database Normalization	First Normal Form (1NF) requires that the table has a primary key and no repeating groups. It sets the foundation for a structured database.
18	Suspicious Email Attachment	I received a phishing email today. The subject was weird and the body contained a hidden span with the text flag{8b1a9953c4611296a827abf8c47804d7} effectively hidden from the render view.
19	React Hooks Tutorial	useEffect is one of the most powerful hooks. It lets you perform side effects in function components, replacing componentDidMount and componentDidUpdate.
20	The history of Linux	Linus Torvalds started Linux as a hobby project in 1991. It has since grown to become the backbone of the internet.
21	Machine Learning Basics	Supervised learning involves training a model on a labeled dataset. Unsupervised learning involves finding patterns in unlabeled data.
22	Why I use Arch Linux	I like having control over my system. Pacman is a fast package manager, and the AUR has almost every piece of software you could imagine.
23	Cryptography Notes	MD5 is considered broken and should not be used for password hashing. However, we still see legacy systems using hashes like FLAG{a87ff679a2f3e71d9181a67b7542122c} for integrity checks.
24	Agile Methodology	Agile is an iterative approach to project management and software development that helps teams deliver value to their customers faster and with fewer headaches.
25	Setting up a Raspberry Pi	First, flash the SD card with the OS image. Enable SSH by placing a file named ssh in the boot directory.
26	Frontend vs Backend	Frontend deals with the visual part of the application that users interact with. Backend deals with the server, database, and application logic.
27	Resolving Merge Conflicts	Git merge conflicts happen when two branches have changed the same part of a file. You have to manually resolve them.
28	Introduction to Go	Go is a statically typed, compiled programming language designed at Google. It i s syntactically similar to C, but with memory safety and garbage collection.
29	Funny variable names	I once saw a variable named 'dontTouchThis' in production code. Naturally, I wanted to touch it.
30	System Crash Report	The server kernel panicked at 03:00 AM. The dump file is huge. I noticed a recurring pattern in the stack trace matching flag{c4ca4238a0b923820dcc509a6f75849b} repeated twice.
31	HTML5 Semantics	Using semantic tags like    and improves accessibility and SEO.
32	Buying a new monitorv	144Hz is a must for gaming. For coding, I prefer a 4k screen for the crisp text rendering.
33	Understanding HTTP codes	200 means OK. 404 means Not Found. 500 means Internal Server Error. 418 means I'm a teapot.
34	JavaScript Promises	Promises are used to handle asynchronous operations in JavaScript. They represent a value which may be available now, or in the future, or never.
35	Hidden Comment Found	Reviewing the PR, I saw a comment left by the previous intern. It just said 'remind me to change flag{e4d909c290d0fb1ca068ffaddf22cbd0} to the real key' and they never did.
36	Bash Scripting Tips	Always quote your variables to prevent word splitting and globbing issues. Use set -e to exit on error.
37	The Art of Unit Testing	Tests should be isolated and independent. If your test relies on the database being in a specific state, it's an integration test.
38	Typescript vs JavaScript	TypeScript is a strict syntactical superset of JavaScript and adds optional static typing to the language.
39	Cloud Computing	AWS, Azure, and GCP are the big three. They offer infrastructure as a service, platform as a service, and software as a service.
40	Analyzing traffic dump	I fired up Wireshark to debug the connection. The handshake looked fine, but the payload contained a string flag{1679091c5a880faf6fb5e6087eb1b2dc} inside the JSON body.
41	Keyboard shortcuts	Ctrl+C and Ctrl+V are the most used shortcuts in a programmer's life. Ctrl+Z is a close second.
42	Microservices Architecture	Microservices structure an application as a collection of loosely coupled services. It improves scalability but adds complexity.
43	Regex pain	Regular expressions are powerful but hard to read. I always use an online tester to verify my patterns before using them.
44	Mobile Development	Flutter allows you to build natively compiled applications for mobile, web, and desktop from a single codebase.
45	DevOps Culture	DevOps is a set of practices that combines software development and IT operations. It aims to shorten the systems development life cycle.
46	Encrypted Message	The client sent over a weird string. I tried decrypting it with their public key but the output was just FLAG{c81e728d9d4c2f636f067f89cc14862c} followed by garbage bytes.
47	Virtual Reality	VR is getting better. The Quest 2 is a great entry-level headset. Developing for VR requires understanding spatial awareness.
48	SQL Injection	Always use prepared statements. Concatenating strings to build SQL queries is a recipe for disaster.
49	Learning New Languages	It keeps your brain sharp. I'm trying to learn Haskell, but the functional paradigm is breaking my brain.
50	Automating boring stuff	I wrote a Python script to organize my downloads folder. It sorts files by extension into different subfolders.
51	Blockchain Hype	Blockchain is a distributed ledger technology. It's the underlying technology behind Bitcoin and other cryptocurrencies.
52	Checking the config	The configuration file was corrupted. I had to restore from backup. The only readable text was the api_key = flag{33e75ff09dd601bbe69f351039152189} line.
53	Game Development	Unity and Unreal Engine are the most popular engines. Indie development is hard work but rewarding.
54	Clean Code	Clean code reads like well-written prose. Meaningful variable names are more important than short code.
55	Internet of Things	IoT devices are everywhere. Security is often an afterthought in these devices, leading to botnets.
56	Functional Programming	Pure functions, immutability, and higher-order functions are core concepts. It reduces side effects.
57	Server Rack Management	Cable management is an art form. A messy rack is a nightmare to troubleshoot when a switch fails.
58	CTF Writeup - Web	I found a hidden directory on the server. Inside was a file named secrets.txt containing the string FLAG{45c48cce2e2d7fbdea1afc51c7c6ad26} which solved the challenge.
59	Quantum Computing	Quantum computers use qubits instead of bits. They can exist in a state of superposition.
60	Open Source Contributions	Contributing to open source is a great way to learn and give back to the community. Start with documentation fixes.
61	REST API Design	Use nouns for resources, not verbs. Use standard HTTP methods like GET, POST, PUT, DELETE.
62	Cybersecurity Trends	Ransomware attacks are on the rise. Zero-trust architecture is becoming the standard for enterprise security.
63	Debug log 455	Error at line 45. Unexpected token. Variable dump shows user_id: 55, session_token: flag{a9bcf1e4d7b95a22e2975c8143b66f35} , status: active.
64	UI/UX Design	User Interface is what you see. User Experience is how you feel when using the product.
65	Code Review Checklist	Check for logic errors, security vulnerabilities, and code style violations. Be constructive in your feedback.
66	Serverless Computing	You don't manage the servers. You just deploy your functions and the cloud provider handles the scaling.
67	Password Security	Use a password manager. Enable 2FA everywhere. Don't reuse passwords across sites.
68	Analyzing the binary	I ran strings on the binary file. Amidst the function names, I spotted a hardcoded debug credential FLAG{eccbc87e4b5ce2fe28308fd9f2a7baf3} which shouldn't be there.
69	The future of AI	AI will transform many industries. We need to consider the ethical implications of automated decision making.
70	Networking Basics	IP addresses identify devices on a network. MAC addresses identify the network interface card.
71	Software Architecture	Monolithic vs Microservices. Event-driven architecture. Layered architecture. Choose the right one for the job.
72	Continuous Integration	CI ensures that code changes are automatically built and tested. It catches bugs early in the development cycle.
73	The Metaverse	Is it the future of the internet or just a buzzword? Only time will tell.
74	Strange Cookie Value	I was auditing the site cookies and noticed the session cookie wasn't base64 encoded. It was literally flag{e9510081ac30ffa83f10b68cde1cac07} in plain text.
75	Graph Databases	Neo4j is a popular graph database. It stores data in nodes and relationships, perfect for social networks.
76	Dark Mode everything	I can't look at light mode anymore. My IDE, browser, and OS are all set to dark mode.
77	Remote Work	Working from home has its pros and cons. Communication is key. Invest in a good chair.
78	5G Technology	5G promises faster speeds and lower latency. It will enable new applications in IoT and autonomous driving.
79	SaaS metrics	CAC, LTV, MRR, ARR. Understanding these metrics is crucial for running a successful SaaS business.
80	Note from the admin	Please stop pasting your credentials in the public chat. I just deleted a message containing FLAG{1f0e3dad99908345f7439f8ffabdffc4} from the general channel.
81	Web Assembly	Wasm allows you to run code written in languages like C++ and Rust in the browser at near-native speed.
82	Ethical Hacking	White hat hackers help companies find vulnerabilities before the bad guys do.
83	Cross-platform apps	Electron allows you to build desktop apps with web technologies. React Native does the same for mobile.
84	Data Privacy	GDPR and CCPA are changing how companies handle user data. Privacy by design is the new standard.
85	Load Balancing	Distributing network traffic across multiple servers ensures no single server bears too much load.
86	Cache invalidation	There are only two hard things in Computer Science: cache invalidation and naming things.
87	Broken Access Control	I was able to view the admin panel by simply changing the URL ID. The footer text mysteriously read flag{c9f0f895fb98ab9159f51fd0297e236d} .
88	Effective Meetings	Have an agenda. Start on time. End on time. Send a follow-up email with action items.
89	Time Management	The Pomodoro technique helps me stay focused. Work for 25 minutes, take a break for 5 minutes.
90	Burnout is real	Take care of your mental health. Don't work weekends if you don't have to. Take vacations.
91	Static Site Generators	Jekyll, Hugo, and Gatsby are popular. They generate static HTML files from Markdown content.
92	GraphQL vs REST	GraphQL allows clients to ask for exactly what they need. No more over-fetching or under-fetching.
93	Memo found on desk	Someone left a sticky note on my monitor. It says 'Do not forget the master key is FLAG{d3d9446802a44259755d38e6d163e820} for the production db'.
94	Command Line proficiency	Learn to love the terminal. Grep, sed, and awk are powerful tools for text processing.
95	Virtual Machines	VMs allow you to run multiple operating systems on a single physical machine. Great for testing.
96	Introduction to Swift	Swift is a powerful and intuitive programming language for iOS, macOS, tvOS, and watchOS.
97	Code Refactoring	Refactoring is the process of restructuring existing computer code without changing its external behavior.
98	API Key Leak	We found a gist on GitHub that contained a live API key. The key format was unusual, looking like flag{6512bd43d9caa6e02c990b0a82652dca} instead of the usual hex string.
99	Choosing a stack	MEAN, MERN, LAMP. There are so many stacks to choose from. Pick the one that solves your problem.
100	Final thoughts	Programming is a journey of constant learning. Stay curious and keep coding.
\.


--
--

SELECT pg_catalog.setval('public.blog_bid_seq', 1, false);


--
--

ALTER TABLE ONLY public.blog
    ADD CONSTRAINT blog_pkey PRIMARY KEY (bid);


--
-- PostgreSQL database dump complete
--