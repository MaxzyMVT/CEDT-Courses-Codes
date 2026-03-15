import Image from "next/image";

export default async function CarDetailPage({ params }: { params: Promise<{ cid: string }> }) {
    
    const { cid } = await params;

    /**
     *  Mock Data for Demonstration Only
     */
    const mockCarRepo = new Map();
    mockCarRepo.set("001", {name: "Henda Covid", image: "/img/car1.jpg"});
    mockCarRepo.set("002", {name: "Henda Airport", image: "/img/car2.jpg"});
    mockCarRepo.set("003", {name: "Yoyoya Fortune Teller", image: "/img/car3.jpg"});
    mockCarRepo.set("004", {name: "Tester 01", image: "/img/car4.jpg"});
    
    return (
        <main className="text-center p-5">
            <h1 className="text-lg font-medium">Car ID {cid}</h1>
            <div className="flex flex-row my-5">
                <Image src={ mockCarRepo.get(cid).image } 
                    alt="Car Image"
                    width={0} height={0} sizes="100vw"
                    className="rounded-lg w-[30%]"/>
                <div className="text-md mx-5">{ mockCarRepo.get(cid).name }</div>
            </div>
        </main>
    );
}

export async function generateStaticParams() {
    return [{cid: "001"}, {cid: "002"}, {cid: "003"}, {cid: "004"}];
}