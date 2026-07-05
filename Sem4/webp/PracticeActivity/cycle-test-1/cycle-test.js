function validateForm() {
    var firstName = document.getElementById('fname').value;
    var lastName = document.getElementById('lname').value;
    var address = document.getElementById('line1').value;
    var phone = document.getElementById('phone').value;
    var email = document.getElementById('email').value;
    var plan = document.querySelector('input[name="plan"]:checked');

    if (!firstName || !lastName || !address || !phone || !email || !plan) {
        alert('Please fill in all the required fields.');
        return false;
    }


    var response = "Confirmation: \n" +
                    "Membership Type: " + plan + "\n" +
                    "Name: " + firstName + " " + lastName + "\n" +
                    "Phone: " + phone;
    var response2 = "Confirmation: <br>" +
                    "Membership Type: " + plan + "<br>" +
                    "Name: " + firstName + " " + lastName + "<br>" +
                    "Phone: " + phone;
    document.getElementById('response').innerHTML = response2;               
    alert(response);
    alert(response);
    return false; 
}