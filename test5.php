<?php
// Autoload the Composer dependencies
require_once 'vendor/autoload.php';

use Facebook\WebDriver\Remote\DesiredCapabilities;
use Facebook\WebDriver\Remote\RemoteWebDriver;
use Facebook\WebDriver\WebDriverBy;
use PhpOffice\PhpSpreadsheet\IOFactory;
use PhpOffice\PhpSpreadsheet\Spreadsheet;

try {
    // Define Selenium WebDriver host and browser capabilities
    $host = 'http://localhost:56404'; // Selenium server address
    $capabilities = DesiredCapabilities::chrome(); // You can also use Firefox

    // Create a new instance of the WebDriver (Chrome in this case)
    $driver = RemoteWebDriver::create($host, $capabilities);

    // Load the Excel file
    $spreadsheet = IOFactory::load('C:\Users\asus\OneDrive\Desktop\college experiment\STQA\grades_practical5.xlsx'); // Path to your Excel file
    $sheet = $spreadsheet->getActiveSheet();

    // Loop through the first 10 rows (starting from row 2 to skip headers)
    for ($row = 2; $row <= 11; $row++) {
        // Get student ID, name, and current grade from Excel file
        $studentId = $sheet->getCell("A$row")->getValue();
        $studentName = $sheet->getCell("B$row")->getValue();
        $currentGrade = $sheet->getCell("C$row")->getValue();

        // Example: Update student grades based on some logic (e.g., bump everyone to 'A')
        $newGrade = 'B';
        $sheet->setCellValue("C$row", $newGrade);

        echo "Updated Student ID $studentId ($studentName) from $currentGrade to $newGrade.\n";

    }

    // Write the updated data back to the Excel file
    $writer = IOFactory::createWriter($spreadsheet, 'Xlsx');
    $writer->save('grades_updated.xlsx'); // Save the updated Excel file

    // Close the browser session
    $driver->quit();

} catch (Exception $e) {
    echo "Error: " . $e->getMessage();
}
