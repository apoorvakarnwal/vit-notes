import { useState } from "react"

function MyComponent(){
    const [name,setName]=useState("Guest");
    const [age,setAge]=useState(0);
    const [isEmployed, setIsEmployed]=useState(false);

    const incrementAge=()=>{
        setAge(age+1);
    }
    const updateName =()=>{
        setName("Spongebob");
    }
    const toggleEmployeeStatus = ()=>{
        setIsEmployed(!isEmployed);
    }
    return(
        <div>
            <p>Name: {name}</p>
            <button onClick={()=>updateName()}>Set Name</button>

            <p>Age: {age}</p>
            <button onClick={()=>incrementAge()}>Increment Age</button>

            <p>Is Employed: {isEmployed?"Yes":"No"}</p>
            <button onClick={toggleEmployeeStatus}>Employee Status</button>
        </div>
    )
}
export default MyComponent;