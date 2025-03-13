<?php
require_once 'classes/CSVReader.php';
require_once 'classes/School.php';

$reader = new CSVReader('Wykaz_szkół_i_placówek_wg_stanu_na_30.IX._2018_w.5.csv');
$page = isset($_GET['page']) ? (int)$_GET['page'] : 1;
$perPage = 25;
$filters = [];

if (isset($_GET['wojewodztwo'])) $filters['wojewodztwo'] = $_GET['wojewodztwo'];
if (isset($_GET['miasto'])) $filters['miasto'] = $_GET['miasto'];
if (isset($_GET['typ'])) $filters['typ'] = $_GET['typ'];

$schools = $reader->getFilteredData($filters, $page, $perPage);
$totalSchools = $reader->getTotalCount($filters);
$totalPages = ceil($totalSchools / $perPage);
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <title>Lista szkół i placówek</title>
    <link rel="stylesheet" href="css/style.css">
</head>
<body>
    <div class="container">
        <form method="GET" class="filter-form">
            <input type="text" name="wojewodztwo" placeholder="Województwo" 
                   value="<?= htmlspecialchars($_GET['wojewodztwo'] ?? '') ?>">
            <input type="text" name="miasto" placeholder="Miasto"
                   value="<?= htmlspecialchars($_GET['miasto'] ?? '') ?>">
            <input type="text" name="typ" placeholder="Typ placówki"
                   value="<?= htmlspecialchars($_GET['typ'] ?? '') ?>">
            <button type="submit">Filtruj</button>
        </form>

        <div class="results">
            <?php foreach ($schools as $school): ?>
                <div class="school-card">
                    <h3><?= htmlspecialchars($school->getName()) ?></h3>
                    <div class="contact-info">
                        <p>Adres: <?= htmlspecialchars($school->getAddress()) ?></p>
                        <p>Telefon: <?= htmlspecialchars($school->getPhone()) ?></p>
                        <p>Email: <?= htmlspecialchars($school->getEmail()) ?></p>
                        <p>WWW: <?= htmlspecialchars($school->getWebsite()) ?></p>
                    </div>
                </div>
            <?php endforeach; ?>
        </div>

        <div class="pagination">
            <?php for ($i = 1; $i <= $totalPages; $i++): ?>
                <a href="?page=<?= $i ?><?= http_build_query(array_merge($_GET, ['page' => $i])) ?>"
                   class="<?= $page === $i ? 'active' : '' ?>"><?= $i ?></a>
            <?php endfor; ?>
        </div>
    </div>
</body>
</html>
