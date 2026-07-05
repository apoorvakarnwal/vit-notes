
function maskPhoneNumber() {
    var input = document.getElementById("mobile");
    var maskedNumber = '';
    var inputValue = input.value.replace(/\D/g, ''); // Remove non-numeric characters

    for (var i = 0; i < inputValue.length; i++) {
        maskedNumber += '#';
    }

    input.value = maskedNumber;
}
function calculateFee() {
    var fee = 0;
    var message = "";
    
    if (document.getElementById("younger").checked) {
        fee = 500;
        message = "Thank you for registering for the athlete training camp for participants 11 years and younger. The fee is Rs.500.";
    } else if (document.getElementById("older").checked) {
        fee = 750;
        message = "Thank you for registering for the athlete training camp for participants 12 years and older. The fee is Rs.750.";
    }
    document.getElementById("confirmation").innerHTML = message;
}