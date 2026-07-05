let add =(num1,num2) => {
    let x=Math.abs(num1);
    let y=Math.abs(num2);
    return x+y;
}
console.log(add(5,-6));

let laptop={
    cpu:'i9',
    ram:'16gb',

    greet: function(){
        console.log(this.cpu);
        console.log('hey there');
    },
    greet2(){
        return 'hey there2';
    }
};

laptop.greet();
console.log(laptop.greet2());

let laptop1={
    cpu:'i9',
    ram:'16gb',

    compare(laptop2){
        if(this.cpu>laptop2.cpu){
            console.log('laptop1 is faster');
        }
        else{
            console.log('laptop2 is faster');
        }
    }
};
let laptop2={
    cpu:'i7',
    ram:'16gb',

};
laptop1.compare(laptop2)