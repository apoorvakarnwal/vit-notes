import { useState } from "react"

function Myfile2(){
    const [name,setName]=useState("Guest");
    const [number,setQuantity]=useState(1);
    const [comment, setComment]=useState('');
    const [payment,setPayment]=useState('');
    const [shipping, setShipping]=useState('');

    function handleNameChange(event){
        setName(event.target.value);
    }
    function handleNumberChange(event){
        setQuantity(event.target.value);
    } 
    function handleCommentChange(event){
        setComment(event.target.value);
    }
    function handlePaymentChange(event){
        setPayment(event.target.value);
    }
    function handleShippingChange(event){
        setShipping(event.target.value);
    }
    return(
        <div>
            <input value={name} onChange={handleNameChange} />
            <p>Name: {name}</p>


            <input value={number} onChange={handleNumberChange} />
            <p>Age: {number}</p>
            
            <textarea value={comment} onChange={handleCommentChange}></textarea>
            <p>Comment: {comment}</p>

            <select value={payment} onChange={handlePaymentChange}>
                <option value="">Select an option</option>
                <option value="Visa">Visa</option>
                <option value="Mastercard" >Mastercard</ option> 
                <option value="Giftcard">Giftcard</option>
            </ select>
            <p>Payment: {payment}</p>

            <input type="radio" value="Pick Up" checked={shipping==="Pick Up"}
                        onChange={handleShippingChange} />
            <label >Pick Up</label>
            <br />
            <input type="radio" value="Delivery" checked={shipping==="Delivery"}
                        onChange={handleShippingChange} />
            <label >Delivery</label>

            <p>Shipping: {shipping}</p>
        </div>
    )
}
export default Myfile2;