import { itemFromObject } from "../models/itemModel.js";
import { items } from "../data/items.js";
import { Console } from "console";

/** @type {import("express").RequestHandler} */
export const createItem = async (req, res) => {
  try {
    const item = itemFromObject(req.body);
    items.push(item);
    res.status(200).json({ message: "OK" });
  } catch (e) {
    console.error(e);
    res.status(400).json({ error: "Bad Request" });
  }
};

/** @type {import("express").RequestHandler} */
export const getItems = async (req, res) => {
  res.status(200).json(items);
};

/** @type {import("express").RequestHandler} */
export const deleteItem = async (req, res) => {
  try {
    const id = parseInt(req.params.id);
    const index = items.findIndex(item => item._id === id);
    
    if (index === -1) {
      res.status(404).json({ error: "Item not found" });
      return;
    }

    items.splice(index, 1);
    res.status(200).json({ message: "OK" });
  } catch (e) {
    console.error(e);
    res.status(400).json({ error: "Bad Request" });
  }
};

/** @type {import("express").RequestHandler} */
export const filterItems = async (req, res) => {
  try {
    const { name } = req.body || {};

    if (!name || name === "ทั้งหมด") {
      res.status(200).json(items);
      return;
    }

    const filtered = items.filter((it) => it.name === name);
    res.status(200).json(filtered);
  } catch (e) {
    console.error(e);
    res.status(400).json({ error: "Bad Request" });
  }
};