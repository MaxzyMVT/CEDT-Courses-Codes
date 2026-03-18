import { getServerSession } from "next-auth"

import { authOptions } from "@/app/api/auth/[...nextauth]/route"
import getUserProfile from "@/libs/getUserProfile"
import { dbConnect } from "@/db/dbConnect"
import { revalidateTag } from "next/cache"
import { redirect } from "next/navigation"
import Car from "@/db/models/Car"

export default async function DashboardPage() {
    
    const session = await getServerSession(authOptions);
    if (!session || !session.user.token) return null;

    const profile = await getUserProfile(session.user.token);
    var createdAt = new Date(profile.data.createdAt);

    const addCar = async (addCarForm: FormData) => {
        "use server"
        const model = addCarForm.get("model");
        const description = addCarForm.get("desc");
        const picture = addCarForm.get("picture");
        const seats = addCarForm.get("seats");
        const doors = addCarForm.get("doors");
        const automatic = addCarForm.get("automatic") === "on";
        const largebags = addCarForm.get("largebags");
        const smallbags = addCarForm.get("smallbags");
        const dayRate = addCarForm.get("dayRate");

        try {
            await dbConnect();
            const newCar = new Car({
                "model": model,
                "description": description,
                "picture": picture,
                "seats": seats,
                "doors": doors,
                "automatic": automatic,
                "largebags": largebags,
                "smallbags": smallbags,
                "dayRate": dayRate
            });
            await newCar.save();
        } catch (error) {
            console.log(error);
        }

        revalidateTag("cars");
        redirect("/car");
    }

    return (
        <main className="bg-[#262626] m-5 p-5">
            <div className="text-2xl">
                {profile.data.name}
            </div>
            <table className="table-auto border-seperate border-spacing-2">
                <tbody>
                    <tr>
                        <td>Email</td>
                        <td>{profile.data.email}</td>
                    </tr>
                    <tr>
                        <td>Tel.</td>
                        <td>{profile.data.tel}</td>
                    </tr>
                    <tr>
                        <td>Member Since</td>
                        <td>{createdAt.toDateString()}</td>
                    </tr>   
                </tbody>
            </table>

            {
                (profile.data.role=="admin") ?
                <form action={addCar}>
                    <div className="text-xl text-blue text-blue-700">Create Car Model</div>
                    <div className="flex items-center w-1/2 my-2">
                        <label className="w-auto block text-gray-700 pr-4" htmlFor="model">
                            Model
                        </label>
                        <input type="text" id="model" name="model" placeholder="Car Model" className="bg-white border-gray-200 rounded w-full p-2 text-gray-700 focus:outline-none focus:border-blue-400" required/>
                    </div>
                    <div className="flex items-center w-1/2 my-2">
                        <label className="w-auto block text-gray-700 pr-4" htmlFor="desc">
                            Description
                        </label>
                        <input type="text" id="desc" name="desc" placeholder="Car Description" className="bg-white border-gray-200 rounded w-full p-2 text-gray-700 focus:outline-none focus:border-blue-400" required/>
                    </div>
                    <div className="flex items-center w-1/2 my-2">
                        <label className="w-auto block text-gray-700 pr-4" htmlFor="picture">
                            Picture
                        </label>
                        <input type="text" id="picture" name="picture" placeholder="URL" className="bg-white border-gray-200 rounded w-full p-2 text-gray-700 focus:outline-none focus:border-blue-400" required/>
                    </div>
                    <div className="flex items-center w-1/2 my-2">
                        <label className="w-auto block text-gray-700 pr-4" htmlFor="seats">
                            Seats
                        </label>
                        <input type="number" id="seats" name="seats" placeholder="4" min={0} max={50} className="bg-white border-gray-200 rounded w-auto p-2 text-gray-700 focus:outline-none focus:border-blue-400" required/>

                        <label className="w-auto block text-gray-700 pr-4 ml-5" htmlFor="doors">
                            Doors
                        </label>
                        <input type="number" id="doors" name="doors" placeholder="4" min={0} max={8} className="bg-white border-gray-200 rounded w-auto p-2 text-gray-700 focus:outline-none focus:border-blue-400" required/>

                        <input type="checkbox" id="automatic" name="automatic"
                        className="ml-5 mr-2"/><span>Auto</span>
                    </div>
                    <div className="flex items-center w-1/2 my-2">
                        <label className="w-auto block text-gray-700 pr-4" htmlFor="largebags">
                            Large Bags
                        </label>
                        <input type="number" id="largebags" name="largebags" placeholder="2" min={0} max={10} className="bg-white border-gray-200 rounded w-auto p-2 text-gray-700 focus:outline-none focus:border-blue-400" required/>


                        <label className="w-auto block text-gray-700 pr-4 ml-5" htmlFor="smallbags">
                            Small Bags
                        </label>
                        <input type="number" id="smallbags" name="smallbags" placeholder="2" min={0} max={10} className="bg-white border-gray-200 rounded w-auto p-2 text-gray-700 focus:outline-none focus:border-blue-400" required/>
                    </div>

                    <div className="flex items-center w-1/2 my-2">
                        <label className="w-auto block text-gray-700 pr-4" htmlFor="dayRate">
                            Rate
                        </label>
                        <input type="text" id="dayRate" name="dayRate" placeholder="Daily Rate (including insurance)" className="bg-white border-gray-200 rounded w-full p-2 text-gray-700 focus:outline-none focus:border-blue-400" required/>
                    </div>
                    <button type="submit" className="bg-blue-500 hover:bg-blue-700 text-white p-2 rounded">Add New Car</button>
                </form>
                : null
            }
        </main>
    )
}