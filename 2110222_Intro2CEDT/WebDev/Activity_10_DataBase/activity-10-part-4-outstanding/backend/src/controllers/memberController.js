import Item from "../models/itemModel.js";
import Member from "../models/memberModel.js";

export const createMember = async (req, res) => {
	// TODO 4: Implement createMember function

	try {
		const newMember = new Member(req.body);
		await newMember.save();
		res.status(200).json({ message: "Added new member" });
	} catch (err) {
		if (err.name === "ValidationError") {
			res.status(400).json({ error: "Bad Request" });
		} else {
			res.status(500).json({ error: "Internal server error." });
		}
	}

	//res.status(501).json({ error: "Not Implemented" });
};

export const getMembers = async (req, res) => {
	// TODO 4: Implement getMembers function

	try {
		const members = await Member.find();
		res.status(200).json(members);
	} catch (err) {
		if (err.name === "ValidationError") {
			res.status(400).json({ error: "Bad Request" });
		} else {
			res.status(500).json({ error: "Internal server error." });
		}
	}

	// res.status(501).json({ error: "Not Implemented" });
};

export const deleteMember = async (req, res) => {
	// TODO 4: Implement deleteMember function

	try {
		const deletedMember = await Member.findByIdAndDelete(req.params.id);

		if (deletedMember) {
			const memberName = deletedMember.name;
			await Item.deleteMany({ name: memberName });
			res.status(200).json({ message: "Member successfully deleted." });
		} else {
			res.status(404).json({ error: "Member not found." });
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
