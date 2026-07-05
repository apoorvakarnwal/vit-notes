function ageCheck(){
    let ageCategory = '';

    let age=Number(document.getElementById('age').value);
    if(age>=12 && age<=60){
        ageCategory='Adult';
    }
    else if(age>60){
        ageCategory='Senior';
    }
    else if(age<12){
        ageCategory='Child';
    }

    document.getElementById('age-category').innerHTML=`Age Category: ${ageCategory}`;
}