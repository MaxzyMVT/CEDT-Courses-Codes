"use client"
import { useState } from "react";
import { VlogPlayer } from "./VlogPlayer";
import Rating from "@mui/material/Rating";
import { useWindowListener } from "@/hooks/useWindowListener";

export function TravelCard() {

    const [playing, setPlaying] = useState(true);
    const [rating, setRating] = useState(0);
    const [pointerPosition, setPointerPosition] = useState({x:0, y:0});

    useWindowListener("pointermove", (e)=>{
        setPointerPosition({x: (e as PointerEvent).clientX, y: (e as PointerEvent).clientY});
    });

    return (
        <div className="w-[80%] shadow-lg mx-[10%] my-10 p-2 rounded-lg bg-gray-200 flex flex-row justify-start gap-5">
            <VlogPlayer vdoSrc="/video/ThailandNatural.mp4" isPlaying={playing}></VlogPlayer>

            <div className="flex flex-col gap-5">
                <div className="text-black">Thailand Natural ({pointerPosition.x + "," + pointerPosition.y})</div>
                
                <button className="block rounded-md bg-sky-600 hover:bg-indigo-600 px-3 py-2 text-white shadow-sm" 
                onClick={() => { setPlaying(!playing) }}>
                    { playing ? "Pause" : "Play" }
                </button>
                
                <Rating 
                onClick={(e) => { e.stopPropagation(); }}
                onChange={(e, value)=>{ if(value!=null) setRating(value)  }}
                value={(rating==undefined) ? 0 : rating} 
                />

            </div>

        </div>
    );
}