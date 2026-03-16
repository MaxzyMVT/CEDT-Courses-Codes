import ProductCard from "./ProductCard";
import Link from "next/link";

export default async function CarCatalog({carJson}: {carJson:Object}) {

    const carJsonReady = await carJson;

    return (
        <>
            Explore {carJsonReady.count} models in our catalog
            <div style={{margin: "20px", display: "flex", flexDirection: "row", flexWrap: "wrap", justifyContent: "space-around", gap: "18px"}}>
                {
                    carJsonReady.data.map( (carItem: Object)=>
                        <Link 
                        href={`/car/${carItem.id}`} 
                        key={carItem.id} 
                        className="w-1/5">
                            <ProductCard 
                            carName={carItem.model} 
                            imgSrc={carItem.picture}
                            />
                        </Link>
                    )
                }
            </div>
        </>
    );
}