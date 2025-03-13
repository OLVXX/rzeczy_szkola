<?php
$acceptLanguage = $_SERVER['HTTP_ACCEPT_LANGUAGE'];

$languageParts = explode(',', $acceptLanguage);

$languageCodes = [];

foreach ($languageParts as $part) {
    $langCode = explode(';', $part)[0];
    $languageCodes[] = $langCode;
}

$languageCodes = array_unique($languageCodes);

print_r($languageCodes);
?>