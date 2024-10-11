<?php
// Autoload the Composer dependencies
require_once 'vendor/autoload.php';

use Facebook\WebDriver\Remote\DesiredCapabilities;
use Facebook\WebDriver\Remote\RemoteWebDriver;
use Facebook\WebDriver\WebDriverBy;

try {
    // Define the WebDriver host and browser capabilities
    $host = 'http://localhost:57449'; // Selenium server address
    $capabilities = DesiredCapabilities::chrome(); // Set the browser (Chrome in this case)

    // Create a new instance of the WebDriver
    $driver = RemoteWebDriver::create($host, $capabilities);

    // Navigate to the HTML page with checkboxes (local or remote URL)
    $driver->get('C:\Users\asus\OneDrive\Desktop\college experiment\STQA\Checkbox9.html'); // Replace with actual file path or URL

    // Find all checkbox elements on the page by input type checkbox
    $checkboxes = $driver->findElements(WebDriverBy::cssSelector('input[type="checkbox"]'));

    // Initialize counters
    $totalCheckboxes = count($checkboxes);
    $checkedCount = 0;
    $uncheckedCount = 0;

    // Loop through all checkboxes to count checked and unchecked boxes
    foreach ($checkboxes as $checkbox) {
        if ($checkbox->isSelected()) {
            $checkedCount++;
        } else {
            $uncheckedCount++;
        }
    }

    // Output the result
    echo "Total checkboxes: $totalCheckboxes\n";
    echo "Checked checkboxes: $checkedCount\n";
    echo "Unchecked checkboxes: $uncheckedCount\n";
fgetc(STDIN);
    // Close the browser session
    $driver->quit();
} catch (Exception $e) {
    echo "Error: " . $e->getMessage();
}
?>
