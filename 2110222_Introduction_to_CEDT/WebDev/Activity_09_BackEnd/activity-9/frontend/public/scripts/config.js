/**
 * @typedef {Object} Item
 * @property {string} _id
 * @property {string} item
 * @property {string} name
 * @property {number} price
 */

/** @typedef {Omit<Item, "_id">} ItemPayload */

export const BACKEND_URL = "http://52.91.93.225:3222";

export const MEMBERS = [
	"เฉลิมราชย์ ทองขาว",
	"พิริยกร ศุภกิจเจริญ",
	"จักราวุธ อ่อนพุทธา",
	"ญาณภัทร จำนงค์สุทธิ์",
	"เมธาสิทธิ์ พนาวงศ์วัชร์",
	"ณภัทร พุทซ้อน",
];
