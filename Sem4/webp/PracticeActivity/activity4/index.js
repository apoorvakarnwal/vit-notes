// Function to calculate entry fee based on age category and entry category
function calculateEntryFee() {
    const ageCategory = document.querySelector('input[name="age"]:checked');
    const entryCategory = document.querySelector('input[name="entry"]:checked');
    let entryFee;

    if (!ageCategory) {
        alert("Please select an age category.");
        return;
    }

    if (!entryCategory) {
        alert("Please select an entry category.");
        return;
    }

    switch (ageCategory.value) {
        case "child":
            entryFee = 300;
            break;
        case "adult":
            if (entryCategory.value === "college") {
                entryFee = 400;
            } else if (entryCategory.value === "family") {
                entryFee = 500;
            }
            break;
        case "senior":
            entryFee = 450;
            break;
        default:
            entryFee = 0; // Default to 0 if age category is not valid
    }

    return entryFee;
}

// Event listener for form submission
document.getElementById('booking-form').addEventListener('submit', function(event) {
    event.preventDefault();

    const entryFee = calculateEntryFee();

    if (entryFee) {
        alert("Entry Fee: Rs. " + entryFee);
    }
});
