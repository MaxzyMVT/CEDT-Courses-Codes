"use client"
import { useReducer } from "react";
import Link from "next/link";
import ProductCard from "@/components/ProductCard";

export default function CarPanel() {

    /**
     *  Mock Data for Demonstration Only
     */
    const mockCarRepo = [
        {cid: "001", name: "Henda Covid", image: "/img/car1.jpg"},
        {cid: "002", name: "Henda Airport", image: "/img/car2.jpg"},
        {cid: "003", name: "Yoyoya Fortune Teller", image: "/img/car3.jpg"},
        {cid: "004", name: "Tester 01", image: "/img/car4.jpg"},
    ]

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
            <div style={{margin: "20px", display: "flex", flexDirection: "row", flexWrap: "wrap", justifyContent: "space-around", gap: "18px"}}>
                {
                    mockCarRepo.map( (carItem)=>
                        <Link href={`/car/${carItem.cid}`} className="w-1/5">
                            <ProductCard 
                            carName={carItem.name} 
                            imgSrc={carItem.image}
                            onCompare={ (car:string)=>dispatchCompare({type:"add", carName:car}) }
                            />
                        </Link>
                    )
                }
            </div>
            <div className="w-full text-xl font-medium">
                Compare List: { compareList.size }
            </div>
            { Array.from(compareList).map( (car)=><div key={car} onClick={ ()=>dispatchCompare({type:"remove", carName:car}) }>{car}</div> ) }
        </div>

    );
}