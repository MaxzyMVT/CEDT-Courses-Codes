import Banner from "@/components/Banner";
import ProductCard from "@/components/ProductCard";
import CarPanel from "@/components/CarPanel";
import styles from "./page.module.css";

export default function Home() {
  return (
      <main>
        <Banner/>
        <CarPanel/>
      </main>
  );
}
