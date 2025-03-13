<?php

class CSVReader {
    private $filepath;
    private $header;
    private $data = null;

    public function __construct($filepath) {
        $this->filepath = $filepath;
        $this->loadData();
    }

    private function loadData() {
        if ($this->data !== null) return;

        $this->data = [];
        $handle = fopen($this->filepath, 'r');
        
        $this->header = fgetcsv($handle, 0, ',');
        
        while (($row = fgetcsv($handle, 0, ',')) !== false) {
            $this->data[] = new School($row, $this->header);
        }
        
        fclose($handle);
    }

    public function getFilteredData($filters = [], $page = 1, $perPage = 25) {
        $filtered = array_filter($this->data, function($school) use ($filters) {
            foreach ($filters as $key => $value) {
                if (!empty($value) && !$school->matchesFilter($key, $value)) {
                    return false;
                }
            }
            return true;
        });

        $offset = ($page - 1) * $perPage;
        return array_slice($filtered, $offset, $perPage);
    }

    public function getTotalCount($filters = []) {
        return count($this->getFilteredData($filters));
    }
}
