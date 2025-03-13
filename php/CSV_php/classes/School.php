<?php

class School {
    private $data;
    private $header;

    public function __construct($data, $header) {
        $this->data = array_combine($header, $data);
    }

    public function getId() {
        return $this->data['Lp.'];
    }

    public function getName() {
        return $this->data['Nazwa szkoły, placówki'];
    }

    public function getAddress() {
        return $this->data['Ulica'] . ' ' . $this->data['Nr domu'] . 
               ', ' . $this->data['Kod poczt.'] . ' ' . $this->data['Poczta'];
    }

    public function getPhone() {
        return $this->data['Telefon'];
    }

    public function getEmail() {
        return $this->data['e-mail'];
    }

    public function getWebsite() {
        return $this->data['WWW'];
    }

    public function matchesFilter($key, $value) {
        $value = mb_strtolower(trim($value));
        
        switch ($key) {
            case 'wojewodztwo':
                return $this->matchWholeWord($this->data['Województwo'], $value);
            case 'miasto':
                return $this->matchWholeWord($this->data['Miejscowość'], $value);
            case 'typ':
                return $this->matchWholeWord($this->data['Nazwa typu'], $value);
            default:
                return false;
        }
    }

    private function matchWholeWord($haystack, $needle) {
        $haystack = mb_strtolower($haystack);
        
        $searchWords = explode(' ', $needle);
        
        foreach ($searchWords as $word) {
            if ($word === '') continue;
            
            $pattern = '/\b' . preg_quote($word, '/') . '\b/u';
            if (!preg_match($pattern, $haystack)) {
                return false;
            }
        }
        return true;
    }
}
