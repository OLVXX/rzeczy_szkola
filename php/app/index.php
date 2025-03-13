<?php
include 'config.php';

$language = negotiateLanguage();

$jsonFile = "languages/$language.json";
if (!file_exists($jsonFile)) {
    $language = $default_language;
    $jsonFile = "languages/$language.json";
}

$content = json_decode(file_get_contents($jsonFile), true);
?>

<!DOCTYPE html>
<html lang="<?php echo $language; ?>">
<head>
    <meta charset="UTF-8">
    <title>Language Application</title>
</head>
<body>
    <h1>Aplikacja Językowa</h1>

    <h2>Wybierz język:</h2>
    <form method="GET">
        <select name="lang" onchange="this.form.submit()">
            <?php foreach ($languages as $lang): ?>
                <option value="<?php echo $lang; ?>" <?php if ($lang == $language) echo 'selected'; ?>>
                    <?php echo strtoupper($lang); ?>
                </option>
            <?php endforeach; ?>
        </select>
    </form>

    <h2>Treści w języku: <?php echo strtoupper($language); ?></h2>
    <p><?php echo htmlspecialchars($content['greetings']); ?></p>
    <p><?php echo htmlspecialchars($content['description']); ?></p>
    <p><?php echo htmlspecialchars($content['tips']); ?></p>
    
    <div style="margin-top: 20px; font-size: 0.8em;">
        <?php
        echo "Current language source: ";
        if (isset($_GET['lang'])) echo "URL parameter";
        elseif (isset($_COOKIE['preferred_lang'])) echo "Cookie";
        elseif (isset($_SERVER['HTTP_ACCEPT_LANGUAGE'])) echo "Browser preference";
        else echo "Default language";
        ?>
    </div>
</body>
</html>