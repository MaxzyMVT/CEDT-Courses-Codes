"use client"

export default function InteractiveCard( { children, contentName } : { children:React.ReactNode, contentName:string } ) {

    function onCarSelected() {
        alert("You selected " + contentName);
    }

    function onCardMouseAction(event:React.SyntheticEvent) {
        if (event.type === "mouseover") {
            event.currentTarget.classList.remove("shadow-[0_8px_25px_rgba(255,255,255,0.08)]");
            event.currentTarget.classList.add("shadow-[0_8px_25px_rgba(255,255,255,0.15)]")
        } else {
            event.currentTarget.classList.remove("shadow-[0_8px_25px_rgba(255,255,255,0.15)]");
            event.currentTarget.classList.add("shadow-[0_8px_25px_rgba(255,255,255,0.08)]")
        }
    }


    return (
        <div className="w-[240px] h-[300px] bg-[#1e1e1e] rounded-lg shadow-[0_8px_25px_rgba(255,255,255,0.08)]" onClick={ ()=>onCarSelected()}
        onMouseOver={ (e)=>onCardMouseAction(e) }
        onMouseOut={ (e)=>onCardMouseAction(e) }
        >
            { children }
        </div>
    )
}