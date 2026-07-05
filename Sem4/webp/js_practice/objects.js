let person = {
    fname: "Apoorva",
    age: 16,
    obj: {
        a: 1,
        b: 2,
    },
    sayhello: function() {
        console.log("Apoorva loves Food");
    }
};
// console.log(typeof person.obj);
// console.log(typeof person.obj);
// console.log()
function loopin(obj12) {
    for (let key in obj12){
        if (typeof obj12[key] === 'object') {
            loopin(obj12[key]);
        }
        else{
            console.log(key, obj12[key]);
        }
    }
}

loopin(person);

person.sayhello();
console.log(person.fname);
person.new1='apoorvakarnwal';
console.log(person);

function Course(a){
    this.message=a,
    this.func = function(){
        console.log("enrolled");
    }
}
const c1=new Course('asdfg');
const c2=new Course('vfrvr');
console.log(typeof c1);
console.log(c2);