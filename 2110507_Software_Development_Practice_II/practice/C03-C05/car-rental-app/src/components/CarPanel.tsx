"use client"
import { useReducer } from "react";
import ProductCard from "@/components/ProductCard";

export default function CarPanel() {

    const compareReducer = (compareList:Set<string>, action:{type:string, carName:string}) => {
        switch (action.type) {
            case "add":
                return new Set( compareList.add(action.carName) );
            case "remove":
                compareList.delete(action.carName);
                return new Set( compareList );
            default:
                return compareList;
        }
    };

    const [compareList, dispatchCompare] = useReducer(compareReducer, new Set<string>());

    return (
        <div>
            <div style={{margin: "20px", display: "flex", flexDirection: "row", flexWrap: "wrap", justifyContent: "space-around"}}>
                <ProductCard carName="Henda Covid" imgSrc="/img/car1.jpg"
                onCompare={ (car:string)=>dispatchCompare({type:"add", carName:car}) }
                />
                <ProductCard carName="Henda Airport" imgSrc="/img/car2.jpg"
                onCompare={ (car:string)=>dispatchCompare({type:"add", carName:car}) }
                />
                <ProductCard carName="Yoyoya Fortune Teller" imgSrc="/img/car3.jpg"
                onCompare={ (car:string)=>dispatchCompare({type:"add", carName:car}) }
                />
                <ProductCard carName="Tester 01" imgSrc="/img/car4.jpg"
                onCompare={ (car:string)=>dispatchCompare({type:"add", carName:car}) }
                />
            </div>
            <div className="w-full text-xl font-medium">
                Compare List: { compareList.size }
            </div>
        </div>

    );
}