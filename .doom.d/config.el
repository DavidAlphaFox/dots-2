(add-to-list 'load-path "~/.doom.d/")
(require '+roam)
(require 'leader)
(require 'keys)
(setq org-agenda-files (directory-files-recursively "~/roam/journal" "\\.org$"))
(setq +org-capture-journal-file "~/blog/content/stack.org")
(setq +org-capture-changelog-file "~/blog/content/nice.org")
(setq +org-capture-todo-file "~/roam/journal/todo.org")
(setq neo-autorefresh 't)
(setq neo-mode-line-type 'default)
(after! highlight-indent-guides
  (highlight-indent-guides-auto-set-faces))

