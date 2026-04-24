if [[ -n $(git status -s) ]]; then
  git add .
  git commit -m "$(date +%d) Solution"
  git push
else
  echo "No changes"
fi

