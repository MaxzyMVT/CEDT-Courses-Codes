db.createCollection("booking", {
	validator: {
		$jsonSchema: {
			bsonType: "object",
			required: [
				"booking_id",
				"patient_id",
				"dentist_id",
				"shop_id",
				"service_ids",
				"status",
				"booking_time",
				"appointment_date",
				"start_time",
				"end_time",
			],
			properties: {
				booking_id: { bsonType: "long" },
				patient_id: { bsonType: "int" },
				dentist_id: { bsonType: "int" },
				shop_id: { bsonType: "int" },
				service_ids: {
					bsonType: "array",
					minItems: 1,
					items: { bsonType: "int" },
					uniqueItems: true,
				},
				status: {
					enum: ["Active", "Cancelled", "Completed"],
				},
				booking_time: { bsonType: "date" },
				appointment_date: { bsonType: "date" },
				start_time: {
					bsonType: "string",
					pattern: "^([01]\\d|2[0-3]):([0-5]\\d)(:[0-5]\\d)?$",
				},
				end_time: {
					bsonType: "string",
					pattern: "^([01]\\d|2[0-3]):([0-5]\\d)(:[0-5]\\d)?$",
				},
			},
		},
	},
});

db.booking.createIndex(
	{ patient_id: 1 },
	{
		unique: true,
		partialFilterExpression: { status: "Active" },
	},
);
