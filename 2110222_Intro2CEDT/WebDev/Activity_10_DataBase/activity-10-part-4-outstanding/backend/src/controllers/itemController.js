import Item from "../models/itemModel.js";

export const createItem = async (req, res) => {
	try {
		const newItem = new Item(req.body);
		await newItem.save();

		res.status(200).json({ message: "OK" });
	} catch (err) {
		if (err.name === "ValidationError") {
			res.status(400).json({ error: "Bad Request" });
		} else {
			res.status(500).json({ error: "Internal server error." });
		}
	}
};

export const getItems = async (req, res) => {
	const items = await Item.find();

	res.status(200).json(items);
};

export const deleteItem = async (req, res) => {
	// TODO 2: Implement deleteItem function

	try {
		const deletedItem = await Item.findByIdAndDelete(req.params.id);

		if (deletedItem) {
			res.status(200).json({ message: "Item successfully deleted." });
		} else {
			res.status(404).json({ error: "Item not found." });
		}
	} catch (err) {
		if (err.name === "CastError") {
			res.status(400).json({ error: "Bad Request" });
		} else {
			res.status(500).json({ error: "Internal server error." });
		}
	}

	// res.status(501).json({ error: "Not Implemented" });
};

export const filterItems = async (req, res) => {
	// TODO 3: Implement filterItems function

	try {
		const { name, lowerPrice, upperPrice } = await req.body;
		const findParams = {};

		if (name != "ทั้งหมด") {
			findParams.name = name;
		}

		findParams.price = { $gte: lowerPrice, $lte: upperPrice };

		const filteredItems = await Item.find(findParams);

		res.status(200).json(filteredItems);
	} catch (err) {
		if (err.name === "CastError") {
			res.status(400).json({ error: "Bad Request" });
		} else {
			res.status(500).json({ error: "Internal server error." });
		}
	}

	// res.status(501).json({ error: "Not Implemented" });
};
