let myStr:string = "Hello World!!";
console.log(myStr);
console.log(getBMI(43, 158));

function getBMI(width:number, height:number):number {
    return width / (height/100 * height/100);
}

class Employee {
    public empId:string;
    private name:string;
    private lastName:string;
    private position:string;
    private salary:number;

    constructor(empId:string, name:string, lastName:string, position:string, salary:number) {
        this.empId = empId;
        this.name = name;
        this.lastName = lastName;
        this.position = position;
        this.salary = salary;
    }

    public bonus(months:number):number {
        return this.salary * months;
    }   
}

let emp1 = new Employee("e001","John","Doe","Engineer",45000);
console.log(emp1.bonus(12));