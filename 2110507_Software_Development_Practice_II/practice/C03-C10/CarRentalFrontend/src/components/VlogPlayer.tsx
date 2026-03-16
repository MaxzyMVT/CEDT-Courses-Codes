"use client"
import { useWindowListener } from "@/hooks/useWindowListener";
import { useRef, useEffect } from "react";

export function VlogPlayer({ vdoSrc, isPlaying} : {vdoSrc:string, isPlaying:boolean}) {

    const vdoRef = useRef<HTMLVideoElement>(null);

    useEffect(() => {
        if (isPlaying) {
            vdoRef.current?.play();
        } else {
            vdoRef.current?.pause();
        }
    }, [isPlaying]);

    useWindowListener("resize", (e)=>{
        // alert("window width = " + (e.target as Window).innerWidth);
    } );

    return (
        <video ref={vdoRef} className="w-[40%]" src={vdoSrc} controls loop muted/>
    );
}