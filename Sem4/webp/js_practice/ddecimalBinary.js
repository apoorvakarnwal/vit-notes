
function binary(decimal){
    let number =decimal;
    let ans=0;
    let value=1;
    while(number!=0){
        let mod=number%2;
        ans= ans +mod*value;
        value*=10;
        number= Math.floor(number/2);
    }
    
    return ans;
}
console.log(binary(15));

function decimal(binary){
    let number= binary;
    let n=number.toString().length;
    let ans=0;
    while(number>0){
        let val=Math.floor(number/(10**(n-1)));
        ans+= val*(2**(n-1));
        n--;
        number= number%(10**n);
    }
    return ans;
}
console.log(decimal(1010));