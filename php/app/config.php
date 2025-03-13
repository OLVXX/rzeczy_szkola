<?php

$default_language = 'pl';
$languages = ['pl', 'en', 'es'];

function negotiateLanguage() {
    global $languages, $default_language;
    
    if (isset($_GET['lang']) && in_array($_GET['lang'], $languages)) {
        setcookie('preferred_lang', $_GET['lang'], time() + (86400 * 30), "/"); // 30 days
        return $_GET['lang'];
    }
    
    if (isset($_COOKIE['preferred_lang']) && in_array($_COOKIE['preferred_lang'], $languages)) {
        return $_COOKIE['preferred_lang'];
    }
    
    if (isset($_SERVER['HTTP_ACCEPT_LANGUAGE'])) {
        $browserLangs = explode(',', $_SERVER['HTTP_ACCEPT_LANGUAGE']);
        foreach ($browserLangs as $lang) {
            $lang = substr(trim(explode(';', $lang)[0]), 0, 2);
            if (in_array($lang, $languages)) {
                return $lang;
            }
        }
    }
    
    return $default_language;
}
?>