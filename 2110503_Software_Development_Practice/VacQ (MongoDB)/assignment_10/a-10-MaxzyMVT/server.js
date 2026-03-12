const express = require("express");
const dotenv = require("dotenv");
const cookieParser = require("cookie-parser");
const connectDB = require("./config/db");
const mongoSanitize = require("express-mongo-sanitize");
const helmet = require("helmet");
const { xss } = require("express-xss-sanitizer");
const rateLimit = require("express-rate-limit");
const hpp = require("hpp");
const cors = require("cors");
const swaggerJsDoc = require("swagger-jsdoc");
const swaggerUI = require("swagger-ui-express");

// Load env vars
dotenv.config({ path: "./config/config.env" });

// Connect to database
connectDB();

// Route files
const hospitals = require("./routes/hospitals");
const auth = require("./routes/auth");
const appointments = require("./routes/appointment");

const app = express();

// Body parser
app.use(express.json());

// Query parser
app.set("query parser", "extended");

// Cookie parser
app.use(cookieParser());

// Fix for Express 5 + express-mongo-sanitize compatibility
app.use((req, res, next) => {
	Object.defineProperty(req, "query", {
		value: req.query,
		writable: true,
		configurable: true,
		enumerable: true,
	});
	next();
});

// Sanitize data
app.use(mongoSanitize());

// Set security headers
app.use(helmet());

// Prevent XSS attacks
app.use(xss());

// Rate limiting
const limiter = rateLimit({
	windowMs: 10 * 60 * 1000, // 10 mins
	max: 100,
});
app.use(limiter);

// Prevent http param pollutions
app.use(hpp());

// Enable CORS
app.use(cors());

// Swagger
const swaggerOptions = {
	swaggerDefinition: {
		openapi: "3.0.0",
		info: {
			title: "Library API",
			version: "1.0.0",
			description: "A simple Express VacQ API",
		},
		servers: [
			{
				url: "http://localhost:" + process.env.PORT + "/api/v1",
			},
		],
	},
	apis: ["./routes/*.js"],
};
const swaggerDocs = swaggerJsDoc(swaggerOptions);

// Mount rounters
app.use("/api/v1/hospitals", hospitals);
app.use("/api/v1/auth", auth);
app.use("/api/v1/appointments", appointments);
app.use("/api-docs", swaggerUI.serve, swaggerUI.setup(swaggerDocs));

const PORT = process.env.PORT || 5000;

const server = app.listen(
	PORT,
	console.log("Server running in", process.env.NODE_ENV, "mode on port", PORT),
);

process.on("unhandledRejection", (err, promise) => {
	console.log(`Error: ${err.message}`);

	// Close server & exit process
	server.close(() => process.exit(1));
});
